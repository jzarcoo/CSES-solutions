#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using vll = vector<ll>;
#define fori(i,a,b) for(int i=a; i<b;i++)
#define pb push_back
#define sz(x) (int)x.size()
#define printr(v) for(auto it = v.rbegin(); it != v.rend(); ++it) cout<<*it + 1<<' ';
ll n, m;
vector<vll> adj;
vll in, out, path;
void dfs(ll u){
    while (!adj[u].empty()) {
        auto v = adj[u].back(); adj[u].pop_back();
        dfs(v);
    }
    path.pb(u);
}
void solve(){
    bool flag = true;
    fori(i,1,n-1){
        if (in[i] != out[i]){
            flag = false;
            break;
        }
    }
    if (!flag || in[0] != out[0] - 1 || out[n-1] != in[n-1] - 1){
        cout<<"IMPOSSIBLE\n";
        return;
    }
    dfs(0);
    if (sz(path) != m + 1){
        cout<<"IMPOSSIBLE\n";
        return;
    }
    printr(path);
}
int main(){
    ios_base::sync_with_stdio(false);cin.tie(nullptr);
    cin >> n >> m;
    adj.resize(n);
    in.resize(n);
    out.resize(n);
    fori(i, 0, m) {
        ll a,b; cin>>a>>b; --a,--b;
        adj[a].pb(b);
        in[b]++;
        out[a]++;
    }
    solve();
    return 0;
}