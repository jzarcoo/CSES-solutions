#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using vll =vector<ll>;
using vvll = vector<vll>;
#define FOR(i,a,b) for(int i=a;i<b;i++)
#define pb push_back
#define rz resize
#define sz(a)(int)a.size()
ll n,q;
const ll NEUTER=-1;
ll m;
vvll tree;
vll height, first, euler, st, vis;
void dfs(ll at=0, ll h=0){
  height[at]=h;
  vis[at]=true;
  first[at]=sz(euler);
  euler.pb(at);
  for(ll to:tree[at]){
	if (!vis[to]){
	  dfs(to, h+1);
	  euler.pb(at);
	}
  }
}
ll comb(const ll l, const ll r){
  if (l==NEUTER) return r;
  if (r==NEUTER) return l;
  return (height[l]<height[r]) ? l : r;
}
void build(ll v, ll b, ll e){
  if (b==e){
	st[v]=euler[b];
	return;
  }
  ll m = b + ((e-b)>>1);
  build(v<<1,b,m);
  build(v<<1|1,m+1,e);
  st[v]=comb(st[v<<1],st[v<<1|1]);
}
ll query(ll v, ll b, ll e, ll l, ll r){
  if (l>e || r<b) return NEUTER;
  if(b>=l && e<=r) return st[v];
  ll m = b + ((e-b)>>1);
  return comb(query(v<<1,b,m,l,r),
			  query(v<<1|1,m+1,e,l,r));
}
ll lca(ll a, ll b){
  ll l = first[a], r=first[b];
  if (l>r)swap(l,r);
  return query(1,0,m-1,l,r);
}
void solve(){
  height.rz(n), first.rz(n), vis.rz(n); euler.reserve((n << 1) - 1);
  dfs();
  m=sz(euler);
  st.resize(m<<2);
  build(1,0,m-1);
  FOR(i,0,q){
	ll a,b;cin>>a>>b;--a,--b;
	cout<<height[a]+height[b]-(height[lca(a,b)]<<1)<<'\n';
  }
}
int main(){
  ios_base::sync_with_stdio(false); cin.tie(nullptr);
  cin>>n>>q;
  tree.rz(n);
  FOR(i,0,n-1){
	ll a,b;cin>>a>>b;--a,--b;
	tree[a].pb(b);
	tree[b].pb(a);
  }
  solve();
  return 0;
}
