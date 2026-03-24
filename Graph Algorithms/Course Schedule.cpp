#include<bits/stdc++.h>
using namespace std;
using ll=long long;
#define fori(i,a,b) for(int i=a; i<b;i++)
#define pb push_back
#define print(v) for(auto &i: v) cout<<i+1<<' ';
#define all(a) a.begin(), a.end()
ll n,m;
vector<vector<ll>> adj;
vector<ll> topo;
void dfs(vector<bool> &vis, ll v){
    vis[v]=true;
    for(ll u:adj[v]){
        if (!vis[u]){
            dfs(vis, u);
        }
    }
    topo.pb(v);
}
void solve(){
    vector<bool> vis(n);
    fori(i,0,n){
        if (!vis[i]){
            dfs(vis, i);
        }
    }
    reverse(all(topo));
    vector<ll> ind(n);
    fori(i,0,n) ind[topo[i]]=i;
    fori(i,0,n){
        for(ll j: adj[i]){
            if (ind[j] <= ind[i]) {
                cout<<"IMPOSSIBLE\n";
                return;
            }
        }
    }
    print(topo);
}
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin>>n>>m;
    adj.resize(n);
    fori(i,0,m){
        ll a,b;cin>>a>>b;--a,--b;
        adj[a].pb(b);
    }
    solve();
    return 0;
}