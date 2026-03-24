#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vll = vector<ll>;
using vvll = vector<vll>;
#define fori(i,a,b) for(int i=a;i<b;i++)
#define pb push_back
#define print(v) for(auto i: v) {cout<<i<<' ';} cout<<endl
ll N;
vvll adj;
vll uno, dos, ans;
void dfs(ll at=0, ll prev=-1){
    for(auto &u: adj[at]){
        if(u==prev) continue;
        dfs(u, at);
        if (uno[u] + 1 > uno[at]){
            dos[at] = uno[at];
            uno[at] = uno[u] + 1;
        } else if (uno[u] + 1 > dos[at]){
            dos[at] = uno[u] + 1;
        }
    }
}
void dfs2(ll at=0, ll prev=-1, ll afuera=0){
    ans[at] = max(afuera, uno[at]);
    for(auto &u: adj[at]){
        if(u==prev) continue;
        if (uno[u] + 1 == uno[at]){
            dfs2(u, at, max(afuera, dos[at]) + 1);
        } else {
            dfs2(u, at, max(afuera, uno[at]) + 1);
        }
    }
}
void solve(){
    dfs();
    dfs2();
    print(ans);
}
int main(){
    ios_base::sync_with_stdio(false);cin.tie(nullptr);
    cin>>N; 
    adj.resize(N);
    uno.resize(N);
    dos.resize(N);
    ans.resize(N);
    fori(i,1,N){
        ll a,b; cin>>a>>b;
        adj[a-1].pb(b-1);
        adj[b-1].pb(a-1);
    }
    solve();
    return 0;
}