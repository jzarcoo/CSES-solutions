#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vll;
typedef vector<vll> vvll;
#define fori(i,a,b) for(int i=a; i<b;i++)
#define pb push_back
#define all(a) a.begin(), a.end()
const ll INF = LLONG_MAX;
ll n, m;
vvll adj;

vector<int> p;
vector<bool> vis;
ll ini, fin;

bool dfs(ll v, ll par){
    vis[v]=true;
    for(ll u:adj[v]){
        if(u==par) continue;
        if(vis[u]){
            fin=v;
            ini=u;
            return true;
        }
        p[u]=v;
        if (dfs(u, p[u])) return true;
    }
    return false;
}
void solve(){
    cin>>n>>m;
    adj.resize(n);
    fori(i,0,m){
        ll x, y; cin>>x>>y;
        adj[x-1].pb(y-1);
        adj[y-1].pb(x-1);
    }
    queue<ll> q;
    p.assign(n,-1);
    vis.assign(n,false);
    ini=-1;
    fori(i,0,n) if (!vis[i] && dfs(i, p[i])) break;
    if (ini==-1){
        cout<<"IMPOSSIBLE\n";
        return;
    }
    vll c;
    c.pb(ini);
    for(ll cur=fin; cur!=ini; cur = p[cur]) 
        c.pb(cur);
    c.pb(ini);
    reverse(all(c));
    cout<<c.size()<<'\n';
    for(ll &x:c) cout<<x+1<<' ';
    cout<<'\n';

}
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    solve();
    return 0;
}