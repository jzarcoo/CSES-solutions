#include<iostream>
#include<vector>
using namespace std;
typedef long long ll;
#define rz resize 
#define FOR(i,a,b) for(int i=a; i<b;i++)
ll n;
vector<vector<ll>> adj;
vector<ll> ans, subtree;
void dfs(ll at=0, ll prev=-1, ll d=0){
  ans[0] += d;
  subtree[at]=1;
  for(ll to:adj[at]){
	if (to!=prev){
	  dfs(to, at, d+1);
	  subtree[at] += subtree[to];
	}
  }
}
void dfs2(ll at=0, ll prev=-1){
  for(ll to : adj[at]){
	if (to != prev){
	  ans[to] = ans[at] + n - (subtree[to] << 1);
	  dfs2(to, at);
	}
  }
}
void solve(){
  dfs();
  dfs2();						
}
int main(){
  ios_base::sync_with_stdio(false); cin.tie(nullptr);
  cin>>n;
  ll a,b;
  ans.rz(n), adj.rz(n), subtree.rz(n);
  FOR(i,0,n-1){
	cin>>a>>b;
	--a,--b;
	adj[a].push_back(b);
	adj[b].push_back(a);
  }
  solve();
  for(ll x: ans){
	cout<<x<<' ';
  }
  return 0;
}
