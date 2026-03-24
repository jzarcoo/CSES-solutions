#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<vector<int>> t, up;
vector<int> depth;
vector<ll> ans;
int n,m,a,b,timer=0,lg;
void dfs(int v, int p){
  up[v][0]=p;
  for(int i=1; i<=lg;++i)
	up[v][i] = up[up[v][i-1]][i-1];
  for(int u : t[v]){
	if(u-p){
	  depth[u]=1+depth[v];
	  dfs(u,v);
	}
  }
}
void dfs2(int v, int p){
  for(int u:t[v]){
	if(u-p){
	  dfs2(u,v);
	  ans[v]+=ans[u];
	}
  }
}
int lca(){
  if(depth[a]<depth[b])
	swap(a,b);
  int k = depth[a]-depth[b];
  for(int i=0;i<lg;++i)
	if(k & (1<<i))
	  a = up[a][i];
  if(a==b) return a;
  for(int i=lg-1;i>=0;--i)
	if(up[a][i]!=up[b][i])
	  a = up[a][i], b = up[b][i];
  return up[a][0];
}
int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  cin>>n>>m;
  t.resize(n);depth.resize(n); ans.resize(n);
  lg=n-1;
  while(lg--){
	cin>>a>>b;--a,--b;
	t[a].push_back(b);
	t[b].push_back(a);
  }
  lg = ceil(log2(n));
  up.assign(n, vector<int>(lg+1));
  dfs(0,0);
  while(m--){
	cin>>a>>b;--a,--b;
	ans[a]++;
	ans[b]++;
	int l = lca();
	ans[l]--;
	if(l)
	  ans[up[l][0]]--;
  }
  dfs2(0,0);
  for(ll x:ans) cout<<x<<' ';
  return 0;
}

