#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using pll = pair<ll,ll>;
using vpll = vector<pll>;
using vll = vector<ll>;
#define fori(i,a,b) for(int i=a; i<b;i++)
#define pb push_back
#define sz(x) (int)x.size()
#define print(v)for(auto &i:v)cout<<i+1<<' '
ll n,m;
vector<vpll> adj;
vll deg, vis, path;
void dfs(ll v){
    while (!adj[v].empty()) {
        auto [u, i] = adj[v].back(); adj[v].pop_back();
        if (!vis[i]) {
            vis[i]=1;
            // cout << u+1<<'\n';
            dfs(u);
        }else{
            // cout << u+1<<"?\n";
        }
    }
    path.pb(v);
}
void solve(){
    fori(i,0,n){
        if (deg[i] % 2) {
            cout << "IMPOSSIBLE\n";
            return;
        }
    }
    dfs(0);
    if (sz(path) != m + 1){
        cout << "IMPOSSIBLE\n";
        return;
    }
    print(path);
}
int main(){
    ios_base::sync_with_stdio(false);cin.tie(nullptr);
    cin >> n >> m;
    adj.resize(n);
    deg.resize(n);
    vis.resize(m);
    fori(i, 0, m) {
        ll a,b; cin>>a>>b; --a,--b;
        adj[a].pb({b, i});
        adj[b].pb({a, i});
        deg[a]++;
        deg[b]++;
    }
    solve();
    return 0;
}