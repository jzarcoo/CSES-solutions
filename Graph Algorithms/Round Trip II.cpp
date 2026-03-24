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

vector<int> p,c;
ll ini, fin;

bool dfs(ll v){
    c[v]=1;
    for(ll u:adj[v]){
        if(c[u]==1){
            fin=v;
            ini=u;
            return true;
        }else if (c[u]==0){
            p[u]=v;
            if (dfs(u)) return true;
        }
    }
    c[v]=2;
    return false;
}
void solve(){
    cin>>n>>m;
    adj.resize(n);
    fori(i,0,m){
        ll x, y; cin>>x>>y;
        adj[x-1].pb(y-1);
    }
    queue<ll> q;
    p.assign(n,-1);
    c.assign(n,0);
    ini=-1;
    fori(i,0,n) if (!c[i] && dfs(i)) break;
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