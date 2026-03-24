#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fori(i,a,b) for (ll i=a; i<b;i++)
typedef pair<ll,ll> pll;
const ll INF=LLONG_MAX;
void solve(){
    ll n,m;
    cin>>n>>m;
    vector<vector<pair<ll, ll>>> adj(n+1, vector<pair<ll, ll>>());
    fori(i,0,m){
        ll a,b,c;cin>>a>>b>>c;
        adj[a].push_back({b,c});
    }
    vector<ll> d(n+1,INF);
    vector<ll> p(n+1,-1);
    d[1]=0;
    priority_queue<pll, vector<pll>, greater<pll>> q;
    q.push({0, 1});
    while (!q.empty()) {
        ll v = q.top().second;
        ll d_v = q.top().first;
        q.pop();
        if (d_v != d[v])
            continue;
        for (auto edge : adj[v]) {
            ll to = edge.first;
            ll len = edge.second;
            if (d[v] + len < d[to]) {
                d[to] = d[v] + len;
                p[to] = v;
                q.push({d[to], to});
            }
        }
    }
    fori(i,1,n+1){
        cout<<d[i]<<" \n"[(i+1==n+1)];
    }
}
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    solve();
    return 0;
}