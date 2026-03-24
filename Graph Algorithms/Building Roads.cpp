#include<bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef vector<vi> vvi;
#define pb push_back
#define fori(i,a,b) for(int i=a;i<b;i++)
#define sz(a) (int) a.size()
int n, m;
vvi adj;
vi vis;
void dfs(int v){
    vis[v] = 1;
    for(int u: adj[v]){
        if (!vis[u]){
            dfs(u);
        }
    }
}
void solve(){
    cin>>n>>m;
    adj.assign(n,vi());
    fori(i,0,m){
        int a, b; cin>>a>>b;
        adj[a-1].pb(b-1);
        adj[b-1].pb(a-1);
    }
    vis.assign(n,0);
    vi aux;
    fori(i,0,n){
        if (!vis[i]){
            aux.pb(i+1);
            dfs(i);
        }
    }
    if (sz(aux)==1){
        cout << 0 <<endl;
        return;
    }
    cout << sz(aux) - 1 <<endl;
    fori(i,1,sz(aux)){
        cout << aux[i-1] << ' ' << aux[i] <<endl;
    }
}
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    solve();
    return 0;
}