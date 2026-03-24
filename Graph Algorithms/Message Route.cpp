#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vll;
typedef vector<vll> vvll;
#define fori(i,a,b) for(int i=a; i<b;i++)
#define pb push_back
#define all(a) a.begin(), a.end()
const ll INF = LLONG_MAX;
void solve(){
    ll n, m; cin>>n>>m;
    vvll adj(n);
    fori(i,0,m){
        ll x, y; cin>>x>>y;
        adj[x-1].pb(y-1);
        adj[y-1].pb(x-1);
    }
    queue<ll> q;
    q.push(0);
    vll d(n,INF);
    vll p(n,-1);
    d[0]=0;
    while (!q.empty()){
        ll cur = q.front(); q.pop();
        for(ll vec : adj[cur]){
            if (d[cur] + 1 < d[vec]){
                d[vec] = d[cur] + 1 ;
                p[vec] = cur;
                q.push(vec);
            }
        }
    }
    if (d[n-1]==INF){
        cout<<"IMPOSSIBLE\n";
        return;
    }
    vll path;
    for(ll cur = n-1; cur != -1; cur = p[cur]){
        path.pb(cur);
    }
    reverse(all(path));
    cout<<path.size()<<'\n';
    for(ll &i:path) cout<<i+1<<' ';
    cout<<'\n';
}
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    solve();
    return 0;
}