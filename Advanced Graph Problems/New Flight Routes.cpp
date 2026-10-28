#include<bits/stdc++.h>
using namespace std;

typedef  pair<int,int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
typedef vector<vi> vvi;

#define fi first
#define se second
#define endl '\n'
#define pb push_back
#define eb emplace_back
#define all(z) z.begin(), z.end()
#define sz(z) (int )z.size()

using graph = vvi;

int n, m;
graph adj;

class SCC{
    public:
        int n, ndfs = 0, nscc=0;
        // - keeps track of the lowest t_in of unclaimed vertices
        // - keeps track of the dfs timestamp of the vertices
        // - stack holding the unclaimed vertices
        // - keeps track of the SCC roots of the vertices
        vi low, tin, st, roots, num;
        const graph &g; // 1-indexed
        vvi components;
        SCC(const vvi &_g): g(_g), n(sz(_g)), low(n), tin(n), roots(n), num(n)
    {
        // applies the tarjan algorithm to all the vertices
        // adds vertices to the components in reverse topological order
        for(int v=1; v<n; v++){
            if(!tin[v]){
                dfs(v);
            }
        }
    }
        void dfs(int at){
            low[at] = tin[at] = ++ndfs;
            st.pb(at);
            for(int to : g[at]){
                if(!tin[to]) { // tree-edge
                    dfs(to);
                    low[at] = min(low[to], low[at]);
                }else if(!roots[to]){
                    // back-edge, cross-edge or forward-edge to an unclaimed vertex
                    low[at] = min(low[at], tin[to]);
                }
            }
            if(tin[at] == low[at]){ // vertex is a root
                nscc++;
                // initializes a new component with root at
                components.pb({at});
                while(true){
                    int u = st.back(); st.pop_back();
                    num[u]= nscc;
                    roots[u] = at; // claims the vertex
                    if(at == u)
                        break;
                    // adds vertex u to the component of at
                    components.back().pb(u);
                }
            }
        }
        void build_condensation_graph(graph &cond, vi &out_deg, vi &in_deg){
            cond = graph(nscc+1);
            out_deg = vi(nscc+1);
            in_deg = vi(nscc+1);
            for(int v=1; v < n; v++){
                for(int to : g[v]){
                    if(roots[to] != roots[v]){
                        int a = num[v];
                        int b = num[to];
                        cond[a].pb(b);
                        out_deg[a]++;
                        in_deg[b]++;
                    }
                }
            }
        }
        void single_scc(){
            if(nscc == 1){
                cout << 0 << endl;
                return;
            }
            graph cond;
            vi out_deg, in_deg;
            build_condensation_graph(cond, out_deg, in_deg);
            vi source, sink;
            for(int v=1; v<=nscc; v++){
                if(in_deg[v]==0)
                    source.pb(v);
                if(out_deg[v]==0)
                    sink.pb(v);
            }
            vi visited(nscc+1);
            function<int(int)> find_sink = [&](int v) -> int{
                visited[v] = 1;
                if(out_deg[v] == 0) return v;
                for(int to : cond[v]){
                    if(visited[to]) continue;
                    int t = find_sink(to);
                    if(t != -1) return t;
                }
                return -1;
            };
            vi ms, mt, matched(nscc+1);
            for(int s : source){
                if(visited[s]) continue;
                int t = find_sink(s);
                if(t != -1){
                    ms.pb(s); mt.pb(t);
                    matched[s] = matched[t] = 1;
                }
            }
            vi un_s, un_t;
            for(int s : source) if(!matched[s]) un_s.pb(s);
            for(int t : sink) if(!matched[t]) un_t.pb(t); 
            vii arcs;
            for(int i=0; i< sz(ms); i++)
                arcs.eb(mt[i], ms[(i+1)%sz(ms)]);
            int k = min(sz(un_s), sz(un_t));
            for(int i=0; i<k; i++)
                arcs.eb(un_t[i], un_s[i]);
            for(int i=k; i<sz(un_s); i++)
                arcs.eb(mt[0], un_s[i]);
            for(int i=k; i<sz(un_t); i++)
                arcs.eb(un_t[i], ms[0]);
            cout << sz(arcs) << endl; // max(sources, sinks)
            for(auto &[a, b]: arcs)
                cout << components[a-1][0] << ' ' << components[b-1][0]<<endl;
        }
};

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin>>n>>m;
    adj.resize(n+1);
    for(int i=0; i<m; i++){
        int a, b; cin>>a>>b;
        adj[a].pb(b);
    }
    SCC scc(adj);
    scc.single_scc();
}
