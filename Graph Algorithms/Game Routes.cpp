#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using vll=vector<ll>;
#define pb push_back
#define sz(x) (int) x.size()
#define fori(i,a,b) for(int i=a;i<b;i++)
#define print(v) for(auto &i:v)cout<<i<<' '
#define all(a) a.begin(),a.end()
const ll MOD = 1e9+7;
ll N, M, ans;
vector<vll> adj;
vll topo, dp, in;
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
            dp[u] = (dp[u] + dp[v]) % MOD;
        }
    }
    cout << dp[N-1] << '\n';
}
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin>>N>>M;
    adj.resize(N); in.resize(N); dp.resize(N);
    ll a, b;
    fori(i,0,M){
        cin>>a>>b;--a,--b;
        adj[a].pb(b);
        in[b]++;
    }
    solve();
    return 0;
}
