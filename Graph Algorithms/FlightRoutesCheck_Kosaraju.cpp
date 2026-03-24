#include<bits/stdc++.h>
using namespace std;
#define rz resize
#define pb push_back
#define fori(i,a,b) for(int i=a;i<b;i++)
typedef vector<int> vi;
typedef vector<vi> vvi;

int n,m;
vvi adj, adj_rev;

int nscc=0;
vi color;
vvi componentes;

void dfs(int at, vi &v, int c, vvi &g){
  color[at]=c;
  for(int to : g[at]) if (!color[to]) dfs(to, v, c, g);
  v.pb(at);
}

void solve(){
  vi orden;
  fori(i,0,n) if (!color[i]) dfs(i, orden, 1, adj);
  color.assign(n,0);
  fori(i,0,n){
	int v = orden[n-i-1]; // orden al reves
	if (!color[v]){
	  vi comp;
	  dfs(v, comp, ++nscc, adj_rev);
	  componentes.pb(comp);
	}
  }
  
  if(nscc==1){
	cout<<"YES\n";
  }else{
	cout<<"NO\n";
	cout<<componentes[1].back()+1<<' '<<componentes[0].back()+1;
  }
}

int main(){
  ios_base::sync_with_stdio(0);cin.tie(0);
  cin>>n>>m;
  adj.rz(n); color.rz(n); adj_rev.rz(n);
  fori(i,0,m){
	int a, b; cin>>a>>b;--a,--b;
	adj[a].pb(b);
	adj_rev[b].pb(a);
  }
  solve();
  return 0;
}
