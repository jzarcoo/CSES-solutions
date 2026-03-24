#include<bits/stdc++.h>
using namespace std;
#define rz resize
#define pb push_back
#define fori(i,a,b) for(int i=a;i<b;i++)
typedef vector<int> vi;

int n,m;
vector<vi> adj;

vi s; // stack
vi onstack;

int ndfs=0;
vi num; // numero de descubrimiento

int nscc=0;
vi comps; // representante
vi low; // vértice mas bajo alcanzable desde v

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
	comps.pb(at);
	while(1){
	  int t= s.back(); s.pop_back();
	  onstack[t]=0; // no olvidar 
	  if (t==at) break;
	}
  }
}

void solve(){
  fori(i,0,n){
	if (num[i]==0) dfs(i);
  }
  if(nscc==1){
	cout<<"YES\n";
  }else{
	cout<<"NO\n";
	cout<<comps[0]+1<<' '<<comps[1]+1;
  }
}

int main(){
  ios_base::sync_with_stdio(0);cin.tie(0);
  cin>>n>>m;
  adj.rz(n);
  int t=m;
  while(t--){
	int a, b; cin>>a>>b;--a,--b;
	adj[a].pb(b);
  }
  low.rz(n); num.rz(n); onstack.rz(n);
  solve();
  return 0;
}
