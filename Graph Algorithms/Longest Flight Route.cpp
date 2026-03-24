#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using vll=vector<ll>;
#define pb push_back
#define sz(x) (int) x.size()
#define fori(i,a,b) for(int i=a;i<b;i++)
#define print(v) for(auto &i:v)cout<<i<<' '
#define all(a) a.begin(),a.end()
const ll INF = LLONG_MAX;
ll N, M;
vector<vll> adj;
vll topo, dp, par, ans, in;
void solve(){
    queue<ll> q;
    fori(i,0,N) if (in[i] == 0) q.push(i);
    while (!q.empty()){
        ll cur = q.front(); q.pop();
        topo.pb(cur);
        for (ll v : adj[cur]){
            if (--in[v] == 0){
                q.push(v);
            }
        }
    }
    dp[0] = 1;
    for (auto &v : topo){
        for (auto &u : adj[v]){
            if (dp[u] < dp[v] + 1){
                dp[u] = dp[v] + 1;
                par[u] = v;
            }
        }
    }
    if (dp[N-1] < 0){
        cout << "IMPOSSIBLE\n";
        return;
    }
    for (ll i = N-1; i != -1; i = par[i]){
        ans.pb(i+1);
    }
    reverse(all(ans));
    cout << dp[N-1] <<'\n';
    print(ans);
}
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin>>N>>M;
    adj.resize(N); in.resize(N); par.assign(N, -1); dp.assign(N, -INF);
    ll a, b;
    fori(i,0,M){
        cin>>a>>b;--a,--b;
        adj[a].pb(b);
        in[b]++;
    }
    solve();
    return 0;
}
