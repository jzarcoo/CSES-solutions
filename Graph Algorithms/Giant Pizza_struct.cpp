#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using vll = vector<ll>;
using vvll = vector<vll>;
#define fori(i,a,b) for(int i=a; i<b;i++)
#define pb push_back
#define all(a) a.begin(), a.end()
struct TwoSatSolver {
    ll n_vars, n_vertices, n_comps=0;
    vvll adj, adj_t, componentes;
    vector<bool> assignment;
    vll comp, topo;
    TwoSatSolver(int _n_vars) : n_vars(_n_vars), n_vertices(2 * n_vars),
                                adj(n_vertices), adj_t(n_vertices), componentes(),
                                assignment(n_vars), comp(n_vertices, -1), topo()
    {
        topo.reserve(n_vertices);
    }
    void dfs(ll at, vll &v, ll val, vvll &g) {
        comp[at] = val;
        for (ll u : g[at]) if (comp[u]==-1) dfs(u, v, val, g);
        v.pb(at);
    }
    bool solve_2SAT() {
        fori(i,0,n_vertices) if (comp[i] == -1) dfs(i, topo, 1, adj);
        comp.assign(n_vertices, -1);
        fori(i,0,n_vertices){
            ll v = topo[n_vertices-i-1];
            if (comp[v]==-1) {
                vll arr;
                dfs(v, arr, n_comps++, adj_t);
                componentes.pb(arr);
            }
        }
        for(int i=0;i<n_vertices;i+=2){
            if (comp[i]==comp[i+1]) return false;
            assignment[i/2] = comp[i]>comp[i+1];
        }
        return true;
    }
    void add_disjunction(int a, bool na, int b, bool nb) {
        a = 2 * a ^ na, b = 2 * b ^ nb;
        ll neg_a = a ^ 1, neg_b = b ^ 1;
        adj[neg_a].pb(b);
        adj[neg_b].pb(a);
        adj_t[b].pb(neg_a);
        adj_t[a].pb(neg_b);
    }
};
void solve(){
    ll n, m; cin>>n>>m;
    TwoSatSolver sol(m);
    char c1, c2;
    ll t1, t2;
    while (cin >> c1>>t1>>c2>>t2) sol.add_disjunction(--t1, c1=='-', --t2, c2=='-');
    if(!sol.solve_2SAT()){
        cout << "IMPOSSIBLE\n";
    }else{
        for(bool b : sol.assignment){
            cout << "-+"[b] << " ";
        }
    }
}
int main(){
    ios_base::sync_with_stdio(false);cin.tie(nullptr);
    solve();
    return 0;
}