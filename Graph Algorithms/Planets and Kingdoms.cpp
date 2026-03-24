#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using pll = pair<ll,ll>;
using vll = vector<ll>;
using vpll = vector<pll>;
#define fori(i,a,b) for(int i=a; i<b;i++)
#define pb push_back
#define print(v) for(auto &i: v) cout<<i<<' ';
#define rall(a) a.rbegin(), a.rend()
#define all(a) a.begin(), a.end()
ll n,m;
vll topo;
vll color;
vector<vll> adj, adj_rev;
void dfs(ll v, bool flag, vector<vll> &g, ll c){
    color[v] = c;
    for(ll u : g[v]){
        if (color[u] == 0) {
            dfs(u, flag, g, c);
        }
    }
    if (flag)
        topo.pb(v);
}
void solve(){
    color.resize(n);
    fori(i,0,n){
        if (color[i]==0){
            dfs(i, true, adj, 1);
        }
    }
    reverse(all(topo));
    color.assign(n, 0);
    ll ans=0;
    for(ll v : topo){
        if (color[v]==0){
            ans++;
            dfs(v, false, adj_rev, ans);
        }
    }
    cout<<ans<<'\n';
    print(color);
}
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin>>n>>m;
    adj.resize(n);
    adj_rev.resize(n);
    fori(i,0,m){
        ll a,b;cin>>a>>b;--a,--b;
        adj[a].pb(b);
        adj_rev[b].pb(a);
    }
    solve();
    return 0;
}