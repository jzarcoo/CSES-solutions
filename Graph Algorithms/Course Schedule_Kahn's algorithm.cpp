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
vector<ll> in;
void solve(){
    queue<ll>q;
    fori(i,0,n) if (in[i]==0) q.push(i);
    while(!q.empty()){
        ll cur = q.front();q.pop();
        topo.pb(cur);
        for(ll v: adj[cur]){
            if (--in[v] == 0){
                q.push(v);
            }
        }
    }
    if (topo.size()!= n){
        cout<<"IMPOSSIBLE\n";
        return;
    }
    print(topo);
}
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin>>n>>m;
    adj.resize(n);
    in.resize(n);
    fori(i,0,m){
        ll a,b;cin>>a>>b;--a,--b;
        adj[a].pb(b);
        in[b]++;
    }
    solve();
    return 0;
}