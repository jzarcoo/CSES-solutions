#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vll;
typedef vector<vll> vvll;
#define fori(i,a,b) for(int i=a;i<b; i++)
#define pb push_back
ll n; 
vvll adj;
vll toleaf;
ll ans=0;
void dfs(ll curr, ll prev=-1){
    ll uno=0, dos=0;
    for(ll u : adj[curr]){
        if (u==prev) continue;
        dfs(u, curr);
        if (toleaf[u] + 1 > uno){
            dos = uno;
            uno = toleaf[u] + 1;
        } else if (toleaf[u] + 1 > dos){
            dos = toleaf[u] + 1;
        }
    }
    toleaf[curr] = uno;
    ans = max(ans, uno + dos);
}
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin>>n;
    adj.resize(n);
    toleaf.resize(n);
    fori(i,1,n){
        ll a,b; cin>>a>>b;
        adj[a-1].pb(b-1);
        adj[b-1].pb(a-1);
    }
    dfs(0);
    cout<<ans<<endl;
    return 0;
}
