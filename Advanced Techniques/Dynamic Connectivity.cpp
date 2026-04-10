#include <bits/stdc++.h>
using namespace std;
#define all(z) z.begin(), z.end()
#define print(v) for(int x:v) cout<<x<<' ';
struct dsu_save{
    int v, rnkv, u, rnku;
    dsu_save(){}
    dsu_save(int v, int rnkv, int u, int rnku)
        : v(v), rnkv(rnkv), u(u), rnku(rnku) {}
};
struct dsu_with_rollbacks{
    vector<int> p, rnk;
    int comps;
    stack<dsu_save> op;
    dsu_with_rollbacks() {}
    dsu_with_rollbacks(int n)
        : p(n), rnk(n, 0), comps(n) {
        iota(all(p), 0);
    }
    int find_set(int v) { return v==p[v] ? v : find_set(p[v]); }
    bool unite(int v, int u){
        v = find_set(v), u = find_set(u);
        if(u==v) return 0;
        comps--;
        if(rnk[v]>rnk[u]) swap(v,u);
        op.emplace(v, rnk[v], u, rnk[u]);
        p[v]=u;
        if(rnk[u]==rnk[v]) rnk[u]++;
        return 1;
    }
    void rollback(){
        if(op.empty()) return;
        auto [v, rnkv, u, rnku] = op.top(); op.pop();
        comps++;
        p[v]=v; rnk[v]=rnkv;
        p[u]=u; rnk[u]=rnku;
    }
};
struct query{
    int v, u;
    bool united;
    query(int v, int u)
        : v(v), u(u) {}
};
struct QueryTree{
    int T;
    dsu_with_rollbacks dsu;
    vector<vector<query>> t;
    QueryTree () {}
    QueryTree (int T, int n) // T events, n nodes
        : T(T), dsu(n), t(4*T + 4) {}
    void add_to_tree(int v,int l, int r, int ul, int ur, query& q){
        if(ul> ur)
            return;
        if(l==ul && r==ur){
            t[v].emplace_back(q); 
            return ;
        }
        int m = l + (r-l)/2;
        add_to_tree(2*v, l, m, ul, min(ur, m), q);
        add_to_tree(2*v+1, m+1, r, max(ul, m+1), ur, q);
    }
    void add_query(query q, int l, int r){
        add_to_tree(1,0,T-1, l, r, q);
    }
    void dfs(int v, int l, int r, vector<int> &ans){
        // when entering the node we will add all the elements that are inside this node
        for(query &q: t[v]){
            // change the structure in O(T(n))
            q.united = dsu.unite(q.v, q.u);
        }
        if(l==r) // leaf: answer the query
            ans[l] = dsu.comps;
        else{ // go further to the children
            int m = l + (r-l)/2;
            dfs(2*v, l, m , ans);
            dfs(2*v+1, m+1, r, ans);
        }
        // Undo the additions when leaving the node
        for(query &q : t[v]){
            // rollback changes in O(T(n))
            if(q.united){
                dsu.rollback();
            }
        }
    }
    vector<int> solve(){
        vector<int> ans(T);
        dfs(1,0,T-1, ans);
        return ans;
    }
};
int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n, m, k; cin>>n>>m>>k; // n,m up to 10^5
    int T = k+1; // events
    QueryTree qt(T, n);
    map<pair<int,int>, int> active_edges; // start time
    for(int i=0; i<m; i++){
        int a, b; cin>>a>>b; --a,--b;
        if(a>b) swap(a, b);
        active_edges[{a, b}] = 0;
    }
    for(int i=1; i<=k; i++){
        int t, a, b; cin>>t>>a>>b; --a,--b;
        if(a>b) swap(a, b);
        if(t==1){
            active_edges[{a, b}] = i;
        }else {
            int ini = active_edges[{a,b}];
            qt.add_query(query(a, b), ini, i-1);
            active_edges.erase({a, b});
        }
    }
    // remaining edges
    for(auto [p, ini] : active_edges){
        qt.add_query(query(p.first, p.second), ini, k);
    }
    vector<int> ans = qt.solve();
    for(int i=0; i<T; i++){
        cout << ans[i] <<' ';
    }    
}
