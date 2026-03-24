#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
typedef vector<ll> vll;
typedef vector<pll> vpll;
typedef vector<vll> vvll;
typedef vector<vpll> vvpll;
#define all(v) v.begin(), v.end()
#define rall(v)v.rbegin(), v.rend()
#define fori(i,a,n) for(ll i=a; i<n;i++)
#define sz(a) (int )a.size()
#define pb push_back
const ll INF = LLONG_MAX;
vvpll adj;
vll dist;
vector<bool> vis;
void solve(){
    ll n, m; cin>>n>>m;
    adj.assign(n+1, vpll());
    dist.assign(n+1, INF);
    vis.assign(n+1,false);
    fori(i,0,m){
        ll a,b,c; cin>>a>>b>>c;
        adj[a].pb({b,c});
        adj[b].pb({a,c});
    }
    priority_queue<pll> pq; // max-heap
    // si yo quiero el minimo, volteo el signo y el mas pequeño va a estar arriba,
    //  por que el mas grande sera mas pequeño al invertir el signo
    ll edges=0;
    ll mn=0;
    pq.push({0, 1});
    dist[1]=0;
    while (edges < n){
        if (pq.empty()){
            cout << "IMPOSSIBLE"<<endl;
            return;
        }
        auto  [weight, vertex] = pq.top(); pq.pop();
        weight *= -1; // truco para obtener el signo real
        if (weight > dist[vertex]) continue;
        ++edges; 
        vis[vertex]=true;
        mn+=weight;
        for(auto &[u, w] : adj[vertex]){
            if (!vis[u] && w < dist[u]){
                dist[u]=w;
                pq.push({-w,u}); // truco para poner los mas pequeños arriba
            }
        }
    }
    cout <<mn<<endl;
}
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0); cout.tie(0);
    solve();
    return 0;
}