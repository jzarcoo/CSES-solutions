#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using vll = vector<ll>;
using vvll = vector<vll>;
#define FOR(i,a,b) for(int i=a; i<b;i++)
#define ROFE(i,a,b) for(int i=a; i>=b; i--)
#define pb push_back
#define sz(a) (int) a.size()
#include <bits/stdc++.h>
using namespace std;
struct LCA {
    vll height, euler, first;
    vvll st;
    vector<bool> visited;
    int n, LOG;
    LCA(const vvll &adj, int root = 0) {
        n = adj.size();
        height.resize(n);
        first.resize(n);
        visited.assign(n, false);
        euler.reserve(2 * n);
        dfs(adj, root);
        build();
    }
    void dfs(const vvll &adj, int node, int h = 0) {
        visited[node] = true;
        height[node] = h;
        first[node] = euler.size();
        euler.push_back(node);
        for (int to : adj[node]) {
            if (!visited[to]) {
                dfs(adj, to, h + 1);
                euler.push_back(node);
            }
        }
    }
    void build() {
        int m = euler.size();
        LOG = __lg(m) + 1;
        st.assign(m, vll(LOG));
        for (int i = 0; i < m; ++i)
            st[i][0] = euler[i];
        for (int j = 1; (1 << j) <= m; ++j) {
            for (int i = 0; i + (1 << j) <= m; ++i) {
                int l = st[i][j - 1];
                int r = st[i + (1 << (j - 1))][j - 1];
                st[i][j] = (height[l] < height[r]) ? l : r;
            }
        }
    }

    int query(int L, int R) {
        int len = R - L + 1;
        int j = __lg(len);
        int l = st[L][j];
        int r = st[R - (1 << j) + 1][j];
        return (height[l] < height[r]) ? l : r;
    }

    int lca(int u, int v) {
        int left = first[u], right = first[v];
        if (left > right)
            swap(left, right);
        return query(left, right);
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
    while (q--) {
        int a, b;
        cin >> a >> b;
        cout << t.lca(a - 1, b - 1) + 1 << '\n';
    }
}
int main(){
    ios_base::sync_with_stdio(false);cin.tie(nullptr);
    solve();
    return 0;
}
