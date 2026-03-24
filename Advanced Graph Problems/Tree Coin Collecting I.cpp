#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef vector<vi> vvi;
#define pb push_back
#define fori(i,a,b) for(int i=a; i<b;i++)
#define ROFE(i,a,b) for(int i=a; i>=b;i--)
#define rz resize
#define sz(a)(int)a.size()
const int INF = INT_MAX;
struct ST{
  vi st;
  int n;
  const int NEUTER=INF;
  ST(vi &arr) {
	n = 1;
	while (n < sz(arr)) n <<= 1;   
	st.assign(2*n, NEUTER);
	fori(i,0,sz(arr))st[n+i]=arr[i];
	ROFE(i,n-1,0) st[i]=comb(st[2*i], st[2*i+1]);
  }
  int comb(const int &a, const int &b){
	return min(a,b);
  }
  int query(int l, int r){
	if (l>r) return NEUTER;
	l+=n, r+=n;
	int ans=NEUTER;
	while(l<=r){
	  if (l&1) ans = comb(ans, st[l++]);
	  if (!(r&1)) ans = comb(ans, st[r--]);
	  l>>=1, r>>=1;
	}
	return ans;
  }
  void update(int p, int val){
	p+=n;
	st[p]=val;
	for(p>>=1;p; p>>=1) st[p] = comb(st[2*p], st[2*p+1]);
  }
};
int n, q;
vi coin, dcoin;
vvi g;
 
void bfs(){
  queue<int> q;
  fori(i,0,n){
	if (coin[i]){
	  dcoin[i]=0;
	  q.push(i);
	}
  }
  while(!q.empty()){
	int at = q.front(); q.pop();
	for(int to :g[at]){
	  if (dcoin[to] > dcoin[at] + 1){
		dcoin[to] = dcoin[at] + 1;
		q.push(to);
	  }
	}
  }
}
// hld
vi parent, depth, heavy, head, pos;
vi base;
int cur_pos;
ST *st_hld;
// lca
int LOG;
vi tin, tout;
vvi up;
int timer=0;
int root=0;
int dfs(int v, int p){
  int size=1, max_c_size=0;
  tin[v]=++timer;
  up[v][0]=p;
  fori(i,1,LOG+1){
	up[v][i]=up[up[v][i-1]][i-1];
  }
  for(int c : g[v]){
	if (p==c) continue;
	parent[c]=v, depth[c] = 1 + depth[v];
	int c_size = dfs(c, v);
	size += c_size;
	if (c_size > max_c_size){
	  max_c_size = c_size;
	  heavy[v]=c;
	}
  }
  tout[v]=++timer;
  return size;
}
void decompose(int v, int h) {
  head[v]=h, pos[v]=cur_pos++;
  base[pos[v]] = dcoin[v];
  if (heavy[v]!=-1) decompose(heavy[v], h);
  for(int c : g[v])
	if (c != parent[v] && c != heavy[v])
	  decompose(c,c);
}
void init(){
  tin.rz(n); tout.rz(n);
  LOG = ceil(log2(n));
  up.assign(n, vi(LOG+1));
  //hld
  parent.rz(n); depth.rz(n); head.rz(n); pos.rz(n);
  base.rz(n);
  heavy.assign(n,-1);
  cur_pos=0;
  parent[root]=-1;
  dfs(root, root);
  decompose(root, 0);
  st_hld = new ST(base);
  base.clear();
}
bool is_ancestor(int u, int v){
  return tin[u] <= tin[v] && tout[u] >= tout[v];
}

int lca(int u, int v){
  if (is_ancestor(u, v))
	return u;
  if (is_ancestor(v, u))
	return v;
  for (int i = LOG; i >= 0; --i) {
	if (!is_ancestor(up[u][i], v))
	  u = up[u][i];
  }
  return up[u][0];
}
int dist(int a, int b){
  int l = lca(a,b);
  return depth[a] + depth[b] - 2*depth[l];
}
int query_hld(int a, int b){
  int res = INF;
  for(; head[a]!=head[b]; b = parent[head[b]]){
	if (depth[head[a]] > depth[head[b]]) swap(a,b);
	int cur_res = st_hld->query(pos[head[b]], pos[b]);
	res = min(res, cur_res);
  }
  if(depth[a]>depth[b]) swap(a,b);
  int cur_res = st_hld->query(pos[a], pos[b]);
  res = min(res, cur_res);
  return res;
}
int main() {
  ios::sync_with_stdio(false); cin.tie(nullptr);
  cin>>n>>q;
  coin.rz(n); for(auto &i:coin) cin>>i;
  g.rz(n);
  fori(i,0,n-1){
	int a,b; cin>>a>>b;--a,--b;
	g[a].pb(b);
	g[b].pb(a);
  }
  dcoin.assign(n,INF);
  bfs();
  init();
  while(q--){
	int a,b; cin>>a>>b; --a,--b;
	int d = dist(a,b);
	int mn = query_hld(a, b);
	cout << d + 2*mn <<'\n';
  }
  return 0;
}
