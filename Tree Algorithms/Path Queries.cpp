// Heavy-Light Descomposition
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vll;
typedef vector<vll> vvll;
#define rz resize
#define pb push_back
#define sz(a) (int)a.size()
#define FOR(i,a,b) for(ll i=(a); i<(b); i++)
#define cinv(v) for(auto &i: v) cin>>i;
struct ST{
  vll st;
  ll n;
  const ll NEUTER=0;
  ST(vll &arr) : n(sz(arr)) {
	st.assign(4*n, NEUTER);
	build(1,0,n-1, arr);
  }
  ll comb(const ll &a, const ll &b){
	ll sum = a+b;
	return sum;
  }
  void build(ll v, ll l, ll r, const vll &arr){
	if (l==r){
	  st[v]=arr[l];
	  return;
	}
	ll m = l + ((r-l)/2);
	build(2*v, l, m, arr);
	build(2*v+1, m+1, r, arr);
	st[v]=comb(st[2*v], st[2*v+1]);
  }
  ll query(ll ql, ll qr, ll v, ll l, ll r){
	if (r < ql || l > qr) return NEUTER;
	if (l >= ql && r <= qr) return st[v];
	ll m = l + ((r-l)/2);
	return comb(query(ql, qr, 2*v, l, m),
				query(ql, qr, 2*v+1, m+1, r));
  }
  void update(ll pos, ll val, ll v, ll l, ll r){
	if (l==r){
	  st[v]=val;
	  return;
	}
	ll m = l + ((r-l)/2);
	if (pos<=m){
	  update(pos, val, 2*v, l, m);
	}else{
	  update(pos, val, 2*v+1, m+1, r);
	}
	st[v]=comb(st[2*v], st[2*v+1]);
  }
  ll query(ll l, ll r){
	if (l>r) return NEUTER;
	return query(l, r, 1, 0, n-1);
  }
  void update(ll pos, ll val){
	update(pos, val, 1,0,n-1);
  }
};
ll n, q;
vll parent,depth,heavy,head,pos;
ll cur_pos;
vvll adj;
vll values;
ST *st=nullptr;
ll dfs(ll v){
  ll size=1;
  ll max_c_size=0;
  for(ll c : adj[v]){
	if (parent[v]==c) continue;
	parent[c] = v, depth[c]=1+depth[v];
	ll c_size = dfs(c);
	size+=c_size;
	if (c_size>max_c_size){
	  max_c_size= c_size;
	  heavy[v]=c;
	}
  }
  return size;
}
void decompose(ll v, ll h){
  head[v]=h, pos[v]=cur_pos++;
  if (heavy[v] != -1){
	decompose(heavy[v], h);	
  }
  for(ll c: adj[v]){
	if (c != parent[v] && c != heavy[v]){
	  decompose(c, c);
	}
  }
}
void init(){
  parent.rz(n), depth.rz(n), head.rz(n), pos.rz(n);
  heavy.assign(n, -1);
  cur_pos=0;
  dfs(0);
  decompose(0,0);
  // segment tree
  vll arr(n,0);
  FOR(v,0,n) {
	arr[pos[v]] = values[v];
  }
  st = new ST(arr);
}
ll query(ll a, ll b){
  ll res=0;
  for(; head[a]!=head[b]; b=parent[head[b]]){
	if (depth[head[a]] > depth[head[b]]) swap(a, b);
	res += st->query(pos[head[b]], pos[b]);
  }
  if (depth[a]>depth[b]) swap(a,b);
  res += st->query(pos[a], pos[b]);
  return res;
}
void solve(ll op){
  if(op==1){
	ll s, x; cin>>s>>x; --s;
	values[s]=x;
	st->update(pos[s], x);
  }else{
	ll s; cin>>s;--s;
	ll ans = query(0, s);
	cout << ans << '\n';
  }
}
int main(){
  ios_base::sync_with_stdio(false);cin.tie(nullptr);
  cin>>n>>q;
  // values
  values.rz(n); cinv(values);
  // tree
  adj.rz(n);
  ll a, b;
  FOR(i,0,n-1){
	cin>>a>>b; --a,--b;
	adj[a].pb(b);
	adj[b].pb(a);
  }
  // prepocessing
  init();
  // solve
  ll op;
  while(q--){
	cin>>op;
	solve(op);
  }
  return 0;
}
