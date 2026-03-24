#include<bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef vector<vi> vvi;
#define rz resize
#define az assign
#define sz(a) (int) a.size()
#define pb push_back
#define FOR(i,a,b) for(int i=a;i<b;i++)
#define ROF(i,a,b) for(int i=a;i>b;i--)
vvi biconnected_components(vvi &g, vi &id, vector<bool> &is_cutpoint){ //n,n,n
  int n = sz(g);
  vvi comps;
  vi stk, tin(n), low(n);
  function<void(int, int, int &)> dfs = [&](int at, int prev, int &timer) {
	tin[at] = low[at] = ++timer;
	stk.pb(at);
	for(int to:g[at]){
	  if (to==prev) continue;
	  if (tin[to]) low[at] = min(low[at], tin[to]);
	  else{
		dfs(to, at, timer);
		low[at] = min(low[at], low[to]);
		if (low[to] >= tin[at]){
		  is_cutpoint[at] = (tin[at] > 1) || (tin[to] > 2);
		  comps.pb({at});
		  while(comps.back().back() != to){
			comps.back().pb(stk.back());
			stk.pop_back();
		  }
		}
	  }
	}
  };  
  int timer = 0;
  dfs(0,-1,timer);
  function<vvi()> build_tree = [&](){
	vvi t(1);
	int node_id = 0;
	FOR(at,0,n){
	  if (is_cutpoint[at]){
		id[at] = node_id++;
		t.pb({});
	  }
	}
	for(auto &comp : comps){
	  int at = node_id++;
	  t.pb({});
	  for(int v : comp){
		if (!is_cutpoint[v]) id[v] = at;
		else {
		  t[at].pb(id[v]);
		  t[id[v]].pb(at);
		}		
	  }
	}
	return t;
  };
  return build_tree();
}
struct LCA {
    vector<int> height, euler, first, segtree;
    vector<bool> visited;
    int n;

    LCA(vector<vector<int>> &adj, int root = 0) {
        n = adj.size();
        height.resize(n);
        first.resize(n);
        euler.reserve(n * 2);
        visited.assign(n, false);
        dfs(adj, root);
        int m = euler.size();
        segtree.resize(m * 4);
        build(1, 0, m - 1);
    }

    void dfs(vector<vector<int>> &adj, int node, int h = 0) {
        visited[node] = true;
        height[node] = h;
        first[node] = euler.size();
        euler.push_back(node);
        for (auto to : adj[node]) {
            if (!visited[to]) {
                dfs(adj, to, h + 1);
                euler.push_back(node);
            }
        }
    }

    void build(int node, int b, int e) {
        if (b == e) {
            segtree[node] = euler[b];
        } else {
            int mid = (b + e) / 2;
            build(node << 1, b, mid);
            build(node << 1 | 1, mid + 1, e);
            int l = segtree[node << 1], r = segtree[node << 1 | 1];
            segtree[node] = (height[l] < height[r]) ? l : r;
        }
    }

    int query(int node, int b, int e, int L, int R) {
        if (b > R || e < L)
            return -1;
        if (b >= L && e <= R)
            return segtree[node];
        int mid = (b + e) >> 1;

        int left = query(node << 1, b, mid, L, R);
        int right = query(node << 1 | 1, mid + 1, e, L, R);
        if (left == -1) return right;
        if (right == -1) return left;
        return height[left] < height[right] ? left : right;
    }

    int lca(int u, int v) {
        int left = first[u], right = first[v];
        if (left > right)
            swap(left, right);
        return query(1, 0, euler.size() - 1, left, right);
    }
};
int main(){
  ios_base::sync_with_stdio(0); cin.tie(0);
  int n,m,q; cin>>n>>m>>q;
  vvi g(n);
  FOR(i,0,m){
	int a,b; cin>>a>>b;
	g[--a].pb(--b);
	g[b].pb(a);
  }
  vi id(n); vector<bool> is_cutpoint(n);
  vvi blockcut_tree = biconnected_components(g, id, is_cutpoint);
  LCA lca = LCA(blockcut_tree);
  auto on_path = [&](int a, int b, int c){
	int x = lca.lca(a,b), y = lca.lca(a,c), z = lca.lca(b,c);
	return x==c || (x==y && z==c) || (x==z && y==c);
  };
  FOR(i,0,q){
	int a,b,c; cin>>a>>b>>c;--a,--b,--c;
		cout << ((a==c||b==c|| (is_cutpoint[c] && on_path(id[a], id[b], id[c])))
				 ? "NO\n" : "YES\n");
  }
  return 0;
}
