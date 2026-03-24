// no todos los ciclos positivos son malos
// => solo si un ciclo positivo es parte de un camino de 1 a n
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = LLONG_MAX;
#define fori(i,a,b) for(int i=a;i<b;i++)
#define pb push_back
struct Edge {
    ll from, to, cost;
};
void solve(){
    ll n,m; cin>>n>>m;
    vector<Edge> edges;
    vector<vector<ll>> rev(n);
    fori(i,0,m){
        ll a, b, cost; cin>>a>>b>>cost;
        edges.pb(Edge{a-1,b-1,-cost});
        rev[b-1].pb(a-1);
    }
    vector<ll> d(n, INF);
    d[0] = 0;
    fori(i,0,n-1){
        for (Edge e : edges){
            if (d[e.from] < INF && d[e.to] > d[e.from] + e.cost) {
                d[e.to] = d[e.from] + e.cost;
            }
        }
    }
    vector<bool> en_ciclo(n, false);
    for (Edge e : edges){
        if (d[e.from] < INF && d[e.to] > d[e.from] + e.cost){
            en_ciclo[e.to]=true;
        }
    }
    vector<bool> vis(n, false);
    function<void(ll)> dfs=[&](ll v){
        vis[v] = true;
        for(ll prev : rev[v]){
            if (!vis[prev]) dfs(prev);
        }
    };
    dfs(n-1);
    fori(i,0,n){
        if (en_ciclo[i] && vis[i]){
            cout<<-1<<'\n';
            return;
        }
    }
    cout<<-d[n-1]<<'\n';
}
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    solve();
    return 0;
}