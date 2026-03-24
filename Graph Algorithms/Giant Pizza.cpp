#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using vll = vector<ll>;
#define fori(i,a,b) for(int i=a; i<b;i++)
#define pb push_back
#define all(a) a.begin(), a.end()
struct Clausula {
    ll uno, dos;
    bool isNegUno, isNegDos;
};
ll n, m, n_scc;
vector<Clausula> clausulas;
vector<vll> adj, rev, comps;
vll topo, scc, val;
void build(){
    adj.resize(2*m);
    rev.resize(2*m);
    for (Clausula &c : clausulas) {
        ll uno = 2 * c.uno + c.isNegUno;
        ll dos = 2 * c.dos + c.isNegDos;
        ll unoNeg = 2 * c.uno + !c.isNegUno;
        ll dosNeg = 2 * c.dos + !c.isNegDos;
        
        adj[unoNeg].pb(dos);
        adj[dosNeg].pb(uno);

        rev[dos].pb(unoNeg);
        rev[uno].pb(dosNeg);
    }
}
void dfs(ll v) {
    scc[v] = 1;
    for (ll u : rev[v]) {
        if (!scc[u]) {
            dfs(u);
        }
    }
    topo.push_back(v);
}
void dfs_rev(ll v) {
    scc[v] = n_scc;
    comps.back().pb(v);
    for (ll u : adj[v]) {
        if (!scc[u]) {
            dfs_rev(u);
        }
    }
}
void build_scc(){
    scc.resize(2 * m);
    fori(i, 0, 2 * m) {
        if (!scc[i]) {
            dfs(i);
        }
    }
    reverse(all(topo));
    scc.assign(2 * m, 0);
    n_scc = 0;
    for (ll &v : topo) {
        if (!scc[v]) {
            ++n_scc;
            comps.pb({});
            dfs_rev(v);
        }
    }
}
void solve() {
    for(ll i = 0; i < 2*m; i+=2) {
        if (scc[i] == scc[i + 1]) {
            cout << "IMPOSSIBLE\n";
            return;
        }
    }
    val.resize(2*m, -1);
    for (vll &comp : comps) {
        ll set_to = 1;
        for (ll &nodo : comp) {
            ll neg = nodo % 2 ? nodo - 1 : nodo + 1;
            if (val[neg] != -1) {
                set_to = !val[neg];
                break;
            }
        }
        for (ll &nodo : comp) {
            val[nodo] = set_to;
        }
    }
    fori(i,0,m){
        cout << (val[2*i] ? "+" : "-")  << " ";
    }
}
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin>>n>>m;
    clausulas.resize(n);
    for (Clausula &c : clausulas) {
        char c1, c2;
        cin >> c1 >> c.uno >> c2 >> c.dos;
        --c.uno; --c.dos;
        c.isNegUno = (c1 == '-');
        c.isNegDos = (c2 == '-');
    }
    build();
    build_scc();
    solve();
    return 0;
}