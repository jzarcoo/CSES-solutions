#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
typedef vector<ll> vll;
typedef vector<pll> vpll;
#define fori(i,a,b) for(int i=a;i<b;i++)
#define pb push_back
#define sz(a) (int )a.size()
#define print(v) for(auto &i: v) cout<<i<<' ';
#define all(a) a.begin(), a.end()
const ll INF=LLONG_MAX;
ll n,m,k;
vector<vpll> adj;

ll a,b,c;
void solve(){
    vector<priority_queue<ll>> dist(n);
    priority_queue<pll> pq;

    pq.push({0, 0});
    dist[0].push(0);

    while(!pq.empty()){
        auto [w, v] = pq.top(); pq.pop();
        w = -w;
        if (w > dist[v].top())
            continue;
        for (auto &[to, len] : adj[v]){
            ll new_dist = w + len;
            if (sz(dist[to]) < k){
                dist[to].push(new_dist);
                pq.push({-new_dist, to});
            } else if (dist[to].top() > new_dist){
                dist[to].pop();
                dist[to].push(new_dist);
                pq.push({-new_dist, to});
            }
        }
    }

    vll ans;
    while(!dist[n-1].empty()){
        ans.pb(dist[n-1].top()); dist[n-1].pop();
    }
    reverse(all(ans));
    print(ans);
}
int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin>>n>>m>>k;
    adj.resize(n);
    fori(i,0,m){
        cin>>a>>b>>c;--a,--b;
        adj[a].pb({b,c});
    }
    solve();
    return 0;
}