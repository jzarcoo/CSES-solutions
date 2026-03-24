#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
typedef vector<ll> vll;
typedef vector<pll> vpll;
#define fori(i,a,b) for (ll i=a; i<b;i++)
#define pb push_back
#define se second
#define fi first
const ll INF=LLONG_MAX;
ll n, m;
vector<vpll> adj;
vector<vpll> adj_rev;
void dijkstra(int ini, vector<vpll> &graph, vll &dist) {
    priority_queue<pll> pq;
    dist.assign(n, INF);
    dist[ini] = 0;
    pq.push({0, ini});
    while (!pq.empty()) {
        auto [w, v] = pq.top(); pq.pop();
        w = -w;
        if (w > dist[v])
            continue;
        for (auto &[to, len] : graph[v]) {
            if (dist[v] + len < dist[to]) {
                dist[to] = dist[v] + len;
                pq.push({-dist[to], to});
            }
        }
    }
}
void solve(){
    vll dist_ini, dist_fin;
    dijkstra(0, adj, dist_ini);
    dijkstra(n-1, adj_rev, dist_fin);
    ll ans = INF;
    fori(i,0,n){
        for (auto &[v, w] : adj[i]) {
            if (dist_ini[i] == INF || dist_fin[v] == INF) 
                continue; 
            ll c = dist_ini[i] + w / 2 + dist_fin[v];
            ans = min(ans, c);
        }
    }
    cout << ans << '\n';
}
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin>>n>>m;
    adj.resize(n); adj_rev.resize(n);
    ll a, b, c;
    fori(i, 0, m){
        cin >> a >> b >> c;
        --a, --b;
        adj[a].pb({b, c});
        adj_rev[b].pb({a, c}); 
    }
    solve();
    return 0;
}