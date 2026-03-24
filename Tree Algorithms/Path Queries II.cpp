#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vll;
typedef vector<int> vi;
typedef vector<vll> vvll;
typedef vector<vi> vvi;
#define rz resize
#define pb push_back
#define sz(a) (int)a.size()
#define FOR(i,a,b) for(int i=(a); i<(b); i++)
#define ROF(i,a,b) for(int i=(a); i>(b); i--)
#define ROFE(i,a,b) for(int i=(a); i>=(b); i--)
#define cinv(v) for(auto &i: v) cin>>i;
struct ST{
  vi st;
  int n;
  const int NEUTER=INT_MIN;
  ST(vi &arr) {
	n = 1;
	while (n < sz(arr)) n <<= 1;   
	st.assign(2*n, NEUTER);
	FOR(i,0,sz(arr))st[n+i]=arr[i];
	ROF(i,n-1,0) st[i]=comb(st[2*i], st[2*i+1]);
  }
  int comb(const int &a, const int &b){
	return max(a,b);
  }
  int query(int l, int r){
	if (l>r) return NEUTER;
	l+=n, r+=n;
	int ans=NEUTER;
	while(l<=r){
	  if (l&1) ans = comb(ans, st[l++]);
	  if (!(r&1)) ans=comb(ans, st[r--]);
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
vvi adj;
vi values;
// segment tree
vi parent,depth,heavy,head,pos;
int cur_pos;
ST *st;
// lca
// int LOG;
// vvi up;
// sparse table
vi first, euler;
vvi lca;

int dfs(int v){
  int size=1, max_c_size=0;
  first[v]=sz(euler);
  euler.pb(v);
  for(int c : adj[v]){
	if (parent[v]==c) continue;
	parent[c] = v, depth[c]=1+depth[v];
	// up[c][0]=v;
	// FOR(i,1,LOG)up[c][i]=up[up[c][i-1]][i-1];
	int c_size = dfs(c);
	size+=c_size;
	if (c_size>max_c_size){
	  max_c_size= c_size;
	  heavy[v]=c;
	}
	euler.pb(v);
  }
  return size;
}
void decompose(int v, int h){
  head[v]=h, pos[v]=cur_pos++;
  //st->update(pos[v], values[v]);
  if (heavy[v] != -1) decompose(heavy[v], h);	
  for(int c: adj[v]) if (c != parent[v] && c != heavy[v]) decompose(c, c);
}
void init(){
  parent.rz(n), depth.rz(n), head.rz(n), pos.rz(n), first.rz(n);
  heavy.assign(n, -1);				
  cur_pos=0;
  // LOG = ceil(log2(n));
  // up.assign(n, vi(LOG));
  dfs(0);
  decompose(0,0);
  vi arr(n,0);
  FOR(v,0,n) {
	arr[pos[v]] = values[v];
  }
  st = new ST(arr);
  int m =sz(euler), log = __lg(m)+1;
  lca.assign(m, vi(log));
  FOR(i,0,m){
	lca[i][0]=euler[i];
  }
  for(int j=1; (1<<j)<=m;j++){
	for(int i=0; i+ (1<<j)<=m; i++){
	  int l = lca[i][j-1];
	  int r = lca[i+(1<<(j-1))][j-1];
	  lca[i][j]= (depth[l] < depth[r]) ? l : r;
	}
  }
}
int get_lca(int a, int b){
  a=first[a], b=first[b]; if(a>b)swap(a,b);
  int len = b - a +1;
  int j=__lg(len);
  int l = lca[a][j];
  int r = lca[b-(1<<j)+1][j];
  return (depth[l]<depth[r])?l:r;
}
int query(int a, int b){
  int res=INT_MIN;
  for(; head[a]!=head[b]; b=parent[head[b]]){
	if (depth[head[a]] > depth[head[b]]) swap(a, b);
	res = max(res, st->query(pos[head[b]], pos[b]));
  }
  if (depth[a]>depth[b]) swap(a,b);
  res = max(res, st->query(pos[a], pos[b]));
  return res;
}
void solve(int op){
  if(op==1){
	int s, x; cin>>s>>x; --s;
	values[s]=x;
	st->update(pos[s], x);
  }else{
	int s,x; cin>>s>>x;--s,--x;
	int sx = get_lca(s, x);
	cout << max(query(s,sx), query(x,sx)) << ' ';
  }
}
int main(){
  ios_base::sync_with_stdio(false);cin.tie(nullptr);
  cin>>n>>q;
  values.rz(n); cinv(values);
  adj.rz(n);
  int a, b;
  FOR(i,0,n-1){
	cin>>a>>b; --a,--b;
	adj[a].pb(b);
	adj[b].pb(a);
  }
  init();
  int op;
  while(q--){
	cin>>op;
	solve(op);
  }
  return 0;
}
