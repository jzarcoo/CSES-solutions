#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;

#define fi first
#define se second
#define pb push_back
#define forn(i,a,b) for(int i=a; i<b; i++)
#define fore(i,a,b) for(int i=a; i<=b; i++)
#define rof(i,a,b) for(int i=a; i>b; i--)
#define rofe(i,a,b) for(int i=a; i>=b; i--)
#define sz(z)(int)z.size()
#define endl '\n'

using graph = vvi;

const int V = 2e5;
const int L = 19;

int has_coin[V];
int n, q;
graph g;

int tin[V], timer = 0;
int et[V+1];
int depth[V];
int up[V][L+1];

void readd(){
    cin>>n>>q;
    g = graph(n);
    forn(i,0,n){
        cin>>has_coin[i];
    }
    forn(i,0,n-1){
        int a, b; cin>>a>>b;
        --a,--b;
        g[a].pb(b);
        g[b].pb(a);
    }
}

void dfs(int v, int p){
    tin[v] = ++timer;
    et[timer] = v;
    up[v][0] = p;
    fore(i,1,L){
        up[v][i] = up[up[v][i-1]][i-1];
    }
    for(int to : g[v]){
        if(to!=p){
            depth[to] = 1 + depth[v];
            dfs(to, v);
        }
    }
}

int kth_parent(int b, int k){
    rofe(i,L, 0){
        if(k & (1<<i)){
            b = up[b][i];
        }
    }
    return b;
}

int lca(int a, int b){
    if(depth[a] > depth[b]) swap(a, b);
    int c = kth_parent(b, depth[b] - depth[a]);
    if(a==c) return a;
    rofe(i,L, 0){
        if(up[a][i] != up[c][i]){
            a = up[a][i];
            c = up[c][i];
        }
    }
    return up[a][0];
}

int dist(int a, int b){
    return depth[a] + depth[b] - 2 * depth[lca(a, b)];
}

set<int> tree;
ll et_len = 0;

bool add_node(int u) {
    if(tree.count(tin[u])) return false;

    if(tree.empty()){
        tree.insert(tin[u]);
        return true;
    }
    auto it = tree.insert(tin[u]).fi;
    auto pv = it == tree.begin() ? prev(tree.end()) : prev(it);
    auto nx = next(it) == tree.end() ? tree.begin() : next(it);

    // vertex
    int vprev = et[*pv];
    int vnext = et[*nx];

    et_len -= dist(vprev, vnext);
    et_len += dist(vprev, u) + dist(u, vnext);
    return true;
}

void remove_node(int v){
    if(sz(tree) == 1){
        tree.erase(tin[v]);
        et_len = 0;
        return;
    }

    auto it = tree.find(tin[v]);
    auto pv = it == tree.begin() ? prev(tree.end()) : prev(it);
    auto nx = next(it) == tree.end() ? tree.begin() : next(it);

    int vprev = et[*pv];
    int vnext = et[*nx];

    et_len -= dist(vprev, v) + dist(v, vnext);
    et_len += dist(vprev, vnext);

    tree.erase(it);
}

void query(){
    int a, b; cin>>a>>b; --a,--b;
    bool add_a = add_node(a);
    bool add_b = add_node(b);

    ll ans = et_len - dist(a, b);
    cout << ans << endl;

    if(add_a) remove_node(a);
    if(add_b) remove_node(b);
}

void solve(){
    dfs(0, 0);
    forn(i,0,n){
        if(has_coin[i]){
            add_node(i);
        }
    }
    while(q--){
        query();
    }
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    readd();
    solve();
}
