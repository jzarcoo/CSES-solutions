#include<bits/stdc++.h>
using namespace std;
const int N=1e5+1;
vector<int> g[N];
unordered_set<int> cutpoints;
int low[N], tin[N];
int n, m, t=0;
void findCutpoints(int v, int p){
  tin[v]=low[v]=++t;
  for(int w : g[v]){
	if(w==p) continue;
	if(tin[w]!=0) low[v] = min(low[v], tin[w]);
	else {
	  findCutpoints(w,v);
	  low[v] = min(low[v], low[w]);
	  if(low[w] >= tin[v]){
		if(tin[v]>1 || tin[w]>2)
		  cutpoints.insert(v);
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
	  findCutpoints(i,i);
  cout<<cutpoints.size()<<endl;
  for(int x  : cutpoints){
	cout<<x<<' ';
  }
  return 0;
}
