#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using vll = vector<ll>;
using vvll = vector<vll>;
#define FOR(i,a,b) for(int i=a; i<b;i++)
#define ROFE(i,a,b) for(int i=a; i>=b; i--)
#define pb push_back
#define sz(a) (int) a.size()
#define rz resize 
struct LCA {
    ll n, m;
    vector<bool> visited;
    vll height, first, euler, st;
    const int NEUTER = -1;
    LCA(vvll &adj, ll root = 0) :
        n(sz(adj)), visited(n), height(n), first(n)
    {
        euler.reserve(2 * n - 1); 
        dfs(adj, root);
        m = sz(euler);
        st.resize(m << 2);
        build(1, 0, m - 1);
    }
    void dfs(vvll &adj, ll v, ll h = 0) {
        visited[v] = true;
        height[v] = h;
        first[v] = sz(euler);
        euler.pb(v);
        for (auto to : adj[v]) {
            if (!visited[to]) {
                dfs(adj, to, h + 1);
                euler.pb(v);
            }
        }
    }
    ll comb(ll l, ll r){
        if (l == NEUTER) return r;
        if (r == NEUTER) return l;
        return (height[l] < height[r]) ? l : r;
    }
    void build(ll v, ll b, ll e) {
        if (b == e) {
            st[v] = euler[b];
            return;
        } 
        ll m = b + ((e-b) >> 1);
        build(v << 1, b, m);
        build(v << 1 | 1, m + 1, e);
        st[v] = comb(st[v<<1], st[v<<1|1]);
    }
    ll query(ll v, ll b, ll e, ll L, ll R) {
        if (b > R || e < L)
            return NEUTER;
        if (b >= L && e <= R)
            return st[v];
        ll m = b + ((e-b) >> 1);
        return comb(query(v << 1, b, m, L, R),
                    query(v << 1 | 1, m + 1, e, L, R));
    }
    ll lca(ll a, ll b) {
        ll l = first[a], r = first[b];
        if (l > r) swap(l, r);
        return query(1, 0, m - 1, l, r);
    }
};
void solve(){
    ll n, q; cin>>n>>q;
    vvll children(n);
    FOR(i,1,n){
        ll boss; cin>>boss;
        children[boss-1].pb(i);
    }
    LCA t(children);
    while(q--){
        ll a, b; cin>>a>>b;
        cout<< t.lca(a-1,b-1) + 1 <<'\n';
    }
}
int main(){
    ios_base::sync_with_stdio(false);cin.tie(nullptr);
    solve();
    return 0;
}
