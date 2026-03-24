#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vll = vector<ll>;
using vvll = vector<vll>;
#define fori(i,a,b) for(int i=a;i<b;i++)
#define pb push_back
ll N, ans;
vvll adj;
vll match;
void dfs(ll v, ll p=-1){
    for(auto &i: adj[v]){
        if(i==p) continue;
        dfs(i,v);
        if (!match[i] && !match[v]){
            match[i]=v+1;
            match[v]=i+1;
            ans++;
        }
    }
}
int main(){
    ios_base::sync_with_stdio(false);cin.tie(nullptr);
    cin>>N; ans=0;
    adj.resize(N);
    match.resize(N);
    fori(i,1,N){
        ll a,b; cin>>a>>b;
        adj[a-1].pb(b-1);
        adj[b-1].pb(a-1);
    }
    dfs(0);
    cout<<ans<<'\n';
    return 0;
}