#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
struct Edge{
  int a, b, w, i;
};

int n, m;
int timer;

vector<Edge> edges;
vector<int> type;
const int N=1e5+1;

vector<pair<int,int>> g[N];
int tin[N], low[N];
int pa[N], len[N];

int get(int x){
  return x==pa[x]?x : pa[x] = get(pa[x]);
}

int comb(int a, int b){
  a=get(a), b=get(b);

  
  g[a].clear();
  g[b].clear();
  tin[a]=tin[b]=low[a]=low[b]=0;
  
  if(a==b) return 0;
  
  if(len[a] < len[b]) swap(a,b);
  len[a]+=len[b];
  pa[b]=a;
  
  return len[a];
}

void dfs(int x, int p){
  low[x]=tin[x]=++timer;
  for(auto &[y, i] : g[x]){
    if(i==p) continue;
    if (tin[y]){
      low[x] = min(low[x],tin[y]);
    }else{
      dfs(y, i);
      low[x] = min(low[x], low[y]);
      if(low[y]> low[x]){
	type[i]=2;
      }
    }
  }
}

void addEdge(int i){
  auto [a,b,_,id] = edges[i];
  a = get(a), b = get(b);
  if(a==b) return;
  g[a].push_back({b,id});
  g[b].push_back({a,id});
  type[id]=1;
}

int main(){
  ios_base::sync_with_stdio(0); cin.tie(0);
  fill(len, len+N, 1);
  iota(pa, pa+N, 0);
  cin>>n>>m;
  edges.reserve(m);
  type.resize(m);
  for(int i=0; i<m; i++){
    int a, b, w; cin>>a>>b>>w;
    edges.push_back(Edge{a,b,w,i});
  }
  sort(edges.begin(), edges.end(), [](Edge a, Edge b){
    return a.w<b.w;
  });

  int l, r;
  for(l=0; l<m; l++){
    r = l;
    while(r+1 < m && edges[r+1].w==edges[r].w) ++r;
    for(int i=l; i<=r; i++){
      addEdge(i);
    }
    
    timer = 0;
    for(int i=l; i<=r; i++){
      int a = get(edges[i].a);
      if (0==tin[a]){
	dfs(a,-1);
      }
    }

    for(int i=l; i<=r; i++){
      comb(edges[i].a, edges[i].b);
    }

    l=r;
    
  }

  for(int i=0; i<m;i++){
    //cout<<type[i]<<'\n';
    if(type[i]==0){
      cout<<"NO\n";
    }else{
      cout<<"YES\n";
    }
  }
  
  return 0;
}
