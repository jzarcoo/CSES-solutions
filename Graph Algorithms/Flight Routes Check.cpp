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
// ll timer=0;
// vpll time_out;
vll topo;
vector<vll> adj, adj_rev;
vector<bool> vis;
void dfs(ll v, bool flag, vector<vll> &g){
    vis[v]=true;
    for(ll u : g[v]){
        if (!vis[u]) {
            dfs(u, flag, g);
        }
    }
    if (flag)
        topo.pb(v);
}
void solve(){
    vis.resize(n);
    fori(i,0,n){
        if (!vis[i]){
            dfs(i, true, adj);
        }
    }
    reverse(all(topo));
    vis.assign(n, false);
    vll ans;
    for(ll v : topo){
        if (!vis[v]){
            ans.pb(v);
            dfs(v, false, adj_rev);
        }
    }
    if (ans.size()==1){
        cout<<"YES\n";
        return;
    }
    cout<<"NO\n";
    cout<<ans[1]+1<<' '<<ans[0]+1<<'\n';
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