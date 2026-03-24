#include<bits/stdc++.h>
using namespace std;
#define rz resize
#define pb push_back
#define fori(i,a,b) for(int i=a;i<b;i++)
#define re(v) for(auto &i:v)cin>>i;
#define all(a) a.begin(), a.end()
#define print(v) for(auto i: v){cout<<i<<' ';} cout<<'\n';
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef long long ll;
typedef vector<ll> vll;

int n,m;
vvi adj;
vi coins;

vi s; // stack
vi onstack;

int ndfs=0;
vi num; // numero de descubrimiento

int nscc=0;
vi low; // vértice mas bajo alcanzable desde v

vi roots; // a que componente pertenece
vvi cond, rcond; // grafica de condensación

vi topo;
vi vis;
vll coinscond;

void dfs(int at){
  low[at]=num[at]=++ndfs;
  onstack[at]=1;
  s.pb(at);
  for(int to : adj[at]){
	if (num[to]==0) dfs(to);
	if (onstack[to]) low[at] = min(low[at], low[to]);
  }
  if (low[at] == num[at]){
	++nscc;
	coinscond.pb(0);
	while(1){
	  int v= s.back(); s.pop_back();
	  onstack[v]=0; // no olvidar
	  roots[v]=nscc-1;
	  coinscond[nscc-1] += coins[v];
	  if (v==at) break;
	}
  }
}

void order(int at){
  vis[at]=1;
  for(int to:cond[at]) if (!vis[to]) order(to);
  topo.pb(at);
}

void solve(){
  // SCC
  fori(i,0,n) if (num[i]==0) dfs(i);
  // Condensation graph reverse
  cond.rz(nscc); rcond.rz(nscc);
  fori(at,0,n){
	for(int to: adj[at]){
	  if (roots[at] != roots[to]) {
		cond[roots[at]].pb(roots[to]);	
		rcond[roots[to]].pb(roots[at]);	
	  }
	}
  }
  // topo
  vis.rz(nscc);
  fori(i,0,nscc){
	if (!vis[i]) {
	  order(i);
	}
  }
  reverse(all(topo));
  vll dp;
  copy(all(coinscond), back_inserter(dp));
  ll ans=0;
  for(int at : topo){
	ll c = coinscond[at];
	for(int from : rcond[at]){
	  dp[at] = max(dp[at], c + dp[from]);
	}
	ans = max(ans, dp[at]);
  }
  cout<<ans<<'\n';
}

int main(){
  ios_base::sync_with_stdio(0);cin.tie(0);
  cin>>n>>m;
  coins.rz(n); re(coins);
  adj.rz(n); 
  fori(i,0,m){
	int a, b; cin>>a>>b;--a,--b;
	adj[a].pb(b);
  }
  low.rz(n); num.rz(n); onstack.rz(n); roots.rz(n);
  solve();
  return 0;
}
