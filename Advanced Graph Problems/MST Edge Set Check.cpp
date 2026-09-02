#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

#define sz(z) (int)z.size()

const int MAXM = 2e5 + 5;
const int MAXV = 1e5 + 5;

struct dsu{
    int n;
    vector<int> len, pa;
    vector<pair<int &,int>> history;
    dsu(int n) :
        n(n),
        len(n+1, 1),
        pa(n+1)
        {
            iota(pa.begin(), pa.end(), 0);
        }
    int find(int x){
        return x == pa[x] ? x : find(pa[x]);
    }
    int unite(int a, int b){
        a = find(a);
        b = find(b);
        if(a==b) return 0;
        if(len[a] < len[b]) swap(a,b);
        history.push_back({len[a], len[a]});
        history.push_back({pa[b],pa[b]});
        len[a]+=len[b];
        pa[b] =a;
        return len[a];
    }
    int snapshot() {
        return history.size();
    }
    void rollback(int until){
        while(history.size() > until) {
            history.back().first = history.back().second;
            history.pop_back();
        }
    }

};
struct Edge{
    int i; // 1-indexed
    int from, to;
    ll w;
    // 0 : never in mst
    // 1 : at least one
    // 2 : always
    int status = 0;
    bool operator<(const Edge &e) const {
        return w < e.w || (e.w==w && i < e.i);
    }
};

int len[MAXV], pa[MAXV];
// vector<Edge> g[MAXV];
vector<pair<int,int>> g[MAXV];

int n, m, q;
vector<Edge> edges; // 0-indexed

int timer;
int tin[MAXV], low[MAXV];

int to_sort[MAXM];

dsu* forest;

int get(int x){
    return x == pa[x] ? x : pa[x] = get(pa[x]);
}

int join(int a, int b){
    a = get(a), b = get(b);

    g[a].clear(); g[b].clear();
    tin[a]=tin[b]=low[a]=low[b] = 0;

    if(a==b) return 0;
    if(len[a]<len[b]) swap(a, b);
    pa[b] = a;
    len[a] += len[b];
    return len[a];
}

void init_dsu(){
    fill(len, len+MAXV, 1);
    iota(pa, pa+MAXV, 0);
    forest = new dsu(n);
}

void dfs(int v, int p = -1){
    tin[v] = low[v] = ++timer;
    bool flag = false;
    for(auto &[to, e_id_sort] : g[v]){
        if(to == p && !flag){
            flag = !flag;
            continue;
        }
        if(tin[to]){
            low[v] = min(low[v], tin[to]);
        }else{
            dfs(to, v);
            low[v] = min(low[v], low[to]);
            if(low[to] > tin[v]){
                edges[e_id_sort].status = 2;
            }
        }
    }
}

void add(int i){ // 0-indexed
    Edge &e = edges[i];
    int a = get(e.from), b = get(e.to);
    if(a == b) return;
    g[a].push_back({b, i});
    g[b].push_back({a, i});
    e.status = 1;
}
void preprocess(){
    init_dsu();
    sort(edges.begin(), edges.end());
    ll mst_cost = 0;
    /*
    for(const Edge &e: edges){
        if(comb(e.from, e.to)){
            mst_cost += e.w;
            e.status = true;
        }
    }
    */
    for(int l=0; l<m; ){
        int r = l;
        while(r+1 <m && edges[r+1].w == edges[l].w) r++;
        // same weight edges[l, r]
        for(int i=l; i<=r; i++){
            add(i);
        }
        timer = 0;
        for(int i=l; i<=r; i++){
            int v = get(edges[i].from);
            if(!tin[v]){
                dfs(v);
            }
        }
        for(int i=l; i<=r; i++){
            Edge &e = edges[i];
            join(e.from, e.to);
        }
        l = r+1;
    }
    for(int i=1; i<=m; i++){
        Edge &e = edges[i-1];
        to_sort[e.i] = i-1;
        if(e.status == 2){
            forest->unite(e.from, e.to);
        }
    }
    /*
    cout <<endl;
    for(int i=1; i<=m; i++){
        Edge &e = edges[to_sort[i]];
        cout << e.from << " " <<e.to << " : " << e.status<<endl;
    }
    */

}
bool query(vector<int> &v){
    int before = forest->snapshot();
    bool has_cycle = false;
    for(int id : v){ // e id sort
        if(has_cycle) continue;
        Edge &e = edges[id];
        if(e.status == 0){
            has_cycle = true;
        }
        if(e.status == 2){
            continue;
        }
        if(forest->unite(e.from, e.to) == 0){
            has_cycle = true;
        }
    }
    forest->rollback(before);
    return !has_cycle;
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    // input
    cin>>n>>m>>q;
    for(int i=1; i<=m; i++){
        int a, b;
        ll w;
        cin>>a>>b>>w;
        edges.push_back(Edge{i,a,b,w});
        // g[a].push_back(Edge{i, a, b, w});
        // g[b].push_back(Edge{i, b, a, w});
    }
    preprocess();
    while(q--){
        int t; cin>>t;
        vector<int> arr;
        for(int i=1; i<=t; i++){
            int e_id; cin>>e_id;
            arr.push_back(to_sort[e_id]);
        }
        cout << (query(arr) ? "YES" : "NO") << '\n';
    }
}
