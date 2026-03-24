#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using vll = vector<ll>;
using vvll = vector<vll>;
#define FOR(i,a,b) for(int i=a; i<b;i++)
#define ROFE(i,a,b) for(int i=a; i>=b; i--)
#define pb push_back
#define sz(a) (int) a.size()
#define print(v) for(auto i:v)cout<<i<<' ';
struct Tree{
    int LOG;
    const vvll &children;
    vvll up;
    vll depth;
    
    Tree(const vvll &g) : 
    LOG(ceil(log2(sz(g)))), children(g),
    up(sz(g), vll(LOG)), depth(sz(g))
    {
        dfs();
        // cout<<LOG<<'\n';
    }
 
    void dfs(ll at=0){
        for(ll next : children[at]){
            depth[next] = 1 + depth[at];
            up[next][0] = at;
            FOR(i, 1, LOG) up[next][i] = up[up[next][i-1]][i-1];
            dfs(next);
        }
    }
 
    ll getKthAncestor(ll at, ll k){
        if (depth[at] < k) return -1;
        FOR(i,0,LOG) if (k & (1LL<<i)) at = up[at][i];
        return at;
    }
};
void solve(){
    ll n, q; cin>>n>>q;
    vvll children(n);
    FOR(i,1,n){
        ll boss; cin>>boss;
        children[boss-1].pb(i);
    }
    Tree t(children);
    while(q--){
        ll v, k; cin>>v>>k;
        ll ans = t.getKthAncestor(v-1, k);
        cout<< ((ans == -1) ? -1 : ans + 1) <<'\n';
    }
}
int main(){
    ios_base::sync_with_stdio(false);cin.tie(nullptr);
    solve();
    return 0;
}
