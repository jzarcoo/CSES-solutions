#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vll;
typedef vector<vll> vvll;
#define fori(i,a,b) for(int i=a;i<b; i++)
#define pb push_back
void dfs(ll curr, ll prev, vvll & adj, vll & sub){
    sub[curr]=1;
    for(ll u : adj[curr] ){
        if (u==prev) continue;
        dfs(u,curr,adj,sub);
        sub[curr]+=sub[u];
    }
}
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    ll n; cin>>n;
    vvll adj(n,vll());
    fori(i,1,n){
        ll x; cin>>x;
        adj[x-1].pb(i);
    }
    vll subordinates(n,0);
    dfs(0, 0,adj, subordinates);
    for(ll x:subordinates){
        cout<<x-1<<' ';
    }
    cout<<endl;
    return 0;
}