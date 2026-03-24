#include<bits/stdc++.h>
using namespace std;
const int N=1e5+1;
vector<int> g[N];
vector<pair<int,int>> bridges;
int low[N], tin[N];
int n, m, t=0;
void findBridges(int v, int p){
  tin[v]=low[v]=++t;
  for(int w : g[v]){
	if(w==p) continue;
	if(tin[w]!=0) low[v] = min(low[v], tin[w]);
	else {
	  findBridges(w,v);
	  low[v] = min(low[v], low[w]);
	  if(low[w] > tin[v]){
		bridges.emplace_back(v,w);
	  }
	}
  }
}
int main(){
  scanf("%d %d", &n, &m);
  for(int i=0,a,b;i<m;i++){
	scanf("%d %d", &a, &b);
	g[a].push_back(b);
	g[b].push_back(a);
  }
  for(int i=1; i<=n;i++)
	if(!tin[i])
	  findBridges(i,i);
  cout<<bridges.size()<<endl;
  for(auto &[a,b] : bridges)
	printf("%d %d\n", a, b);
  return 0;
}
