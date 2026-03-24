#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vll;
typedef vector<vll> vvll;
#define fori(i,a,b) for(int i=a;i<b; i++)
#define pb push_back
ll n, timer;
vvll adj;
vll time_in, time_out;
void dfs(ll cur, ll prev){
    time_in[cur] = timer++;
    for(ll u : adj[cur] ){
        if (u!=prev) dfs(u, cur);
    }
    time_out[cur]=timer;
}
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n;
    adj.assign(n,vll());
    fori(i,1,n){
        ll x; cin>>x;
        adj[x-1].pb(i);
    }
    timer=0; time_in.resize(n); time_out.resize(n);
    dfs(0, -1);
    fori(i,0,n){
        cout << time_out[i] - time_in[i] - 1 << ' ';
    }
    cout<<'\n';
    return 0;
}