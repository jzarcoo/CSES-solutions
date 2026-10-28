#include<bits/stdc++.h>
using namespace std;

typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
typedef vector<vi> vvi;

#define fi first
#define se second
#define rep(i,n) for(int i=0; i<n; i++)
#define forn(i,a,n) for(int i=a; i<n; i++)
#define fore(i,a,n) for(int i=a; i<=n; i++)
#define pb push_back
#define sz(z)(int)z.size()
#define all(z)z.begin(),z.end()
#define endl '\n'

const int INF = INT_MAX;

using graph = vvi;

int n, m;
graph g, rg;
int timer = 0;
vi tin, et, parent,
   dsu_parent, dsu_min,
   sdom, rdom, idom;
vii sdom_times;
template<class T>
class LCA{
    private:
        const int R = 0;
        const int N;
        const int L;
        const vi &pa;
        const vector<T> &vals;
        vi depth;
        vvi up;
        vector<vector<T>> pow2;
        void process(){
            vvi children(N);
            rep(i,N){
                if(pa[i] != -1){
                    children[pa[i]].pb(i);
                }
            }
            stack<int> frontier({R});
            while(!frontier.empty()){
                int curr = frontier.top(); frontier.pop();
                for(int to : children[curr]){
                    depth[to] = 1 + depth[curr];
                    frontier.push(to);
                }
            }
        }
    public:
        LCA(const vi &pa,
                const vector<T> &vals)
            : N(sz(pa)),
            L(ceil(log2(N + 1))),
            pa(pa),
            vals(vals),
            depth(N),
            up(N, vi(L + 1)),
            pow2(N, vector<T>(L+1))
    {
        process();
        rep(u,N){
            up[u][0] = pa[u];
            pow2[u][0] = vals[u];
        }
        fore(i,1,L){
            rep(v, N){
                int halfway = up[v][i-1];
                if(halfway == -1){
                    up[v][i] = -1;
                    pow2[v][i] = pow2[v][i-1];
                }else{
                    up[v][i] = up[halfway][i-1];
                    pow2[v][i] = min(pow2[v][i-1], pow2[halfway][i-1]);
                }
            }
        }
    }
    /*
     * Return the min value on the path from the ancestor to its descendant,
     * not including the ancestor.
     */
    T min_val(int ancestor, int desc){
        int dist = depth[desc] - depth[ancestor];
        T ret = vals[desc];
        int at = desc;
        fore(i,0,L){
            if((dist & (1<<i)) != 0){
                ret = min(ret, pow2[at][i]);
                at = up[at][i];
            }
        }
        return ret;
    }
};
int dsu_find(int u){
    if(dsu_parent[u] == - 1) return u;
    if(dsu_parent[dsu_parent[u]] != -1){
        int parent_res = dsu_find(dsu_parent[u]);
        if (tin[parent_res] < tin[dsu_min[u]]){
            dsu_min[u] = parent_res;
        }
        // path compression
        dsu_parent[u] = dsu_parent[dsu_parent[u]];
    }
    return dsu_min[u];
}
void dfs(int at, int prev){
    if(tin[at] != INF) return;
    tin[at] = timer++;
    et.pb(at);
    parent[at] = prev;
    for(int to : g[at]){
        dfs(to, at);
    }
}
void dominator_tree(){
    // euler tour
    tin = vi(n, INF);
    parent = vi(n, -1);
    dfs(0, -1);
    // dsu init
    dsu_parent = vi(n, -1);
    dsu_min = vi(n, INF);
    // sdom computation
    sdom = vi(n, -1);
    // reverse preorder
    for(int i=sz(et)-1; i>0; i--){
        int u = et[i];
        // sdom
        for(int from : rg[u]){
            int find_res = dsu_find(from);
            if(sdom[u] == -1 || tin[find_res] < tin[sdom[u]]){
                sdom[u] = find_res;
            }
        }
        // link u to its parent in the DFS tree
        dsu_parent[u] = parent[u];
        dsu_min[u] = sdom[u];
    }
    sdom_times = vii(n, {INF, -1});
    for(int v : et){
        if(v != 0){
            sdom_times[v] = {tin[sdom[v]], v};
        }
    }
    LCA<ii> tree(parent, sdom_times);
    rdom = vi(n, -1);
    for(int v : et){
        if(v!=0){
            rdom[v] = tree.min_val(sdom[v], v).se;
        }
    }
    idom = vi(n, -1);
    for(int v: et){
        if(v!=0){
            idom[v] = rdom[v]==v ? sdom[v] : idom[rdom[v]];
        }
    }
}
void get_input(){
    cin>>n>>m;   
    g = graph(n);
    rg = graph(n);
    rep(i,m){
        int a, b; cin>>a>>b;--a,--b;
        g[a].pb(b);
        rg[b].pb(a);
    }
}
void solve(){
    get_input();
    dominator_tree();
    vi critical{0};
    int at = n-1;
    while(at != 0){
        critical.pb(at);
        at = idom[at];
    }
    sort(all(critical));
    cout << sz(critical) << endl;
    rep(i,sz(critical)){
        cout << critical[i] + 1 << " \n"[i+1==sz(critical)];
    }
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    solve();
}
