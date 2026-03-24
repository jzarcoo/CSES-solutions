#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
#define pb push_back
#define fi first
#define se second
const int N = 2e5+1;

struct Query{
  int a,b,i;
};

int n, m, q;
int len[N], pa[N];
vii edges;
vector<Query> queries;

void init(){
  memset(len,1,sizeof len);
  iota(pa, pa+N, 0);
}
int get(int x){
  return x==pa[x]?x : pa[x] = get(pa[x]);
}
int comb(int a, int b){
  a=get(a), b=get(b);
  if(a==b) return 1;
  if (len[a]<len[b]) swap(a,b);
  len[a]+=len[b];
  pa[b]=a;
  return len[a];
}
int same(int a, int b){
  return get(a)==get(b);
}

int main(){
  ios_base::sync_with_stdio(0); cin.tie(0);
  cin>>n>>m>>q;
  
  vi lo(q, -1), hi(q, m), ans(q,-1);
  vector<vector<Query>> buckets(m);

  
  for(int i=0; i<m; i++){
    int a, b; cin>>a>>b;
    edges.pb({a, b});
  }
  for(int i=0; i<q; i++){
    int a, b; cin>>a>>b;
    queries.pb(Query{a,b,i});
  }
  init();
  while(1){
    bool f = 1;
    for(int i=0; i<q; i++){
      if(hi[i]==1+lo[i]) continue;
      f=0;
      int mid = lo[i] + (hi[i]-lo[i]) / 2;
      buckets[mid].pb(queries[i]);
    }
    if (f) break;
    for(int d=0; d<m; d++){
      comb(edges[d].fi, edges[d].se);
      for(auto [a,b,i] : buckets[d]){
	if(same(a, b)){
	  ans[i]=d+1;
	  hi[i] = d;
	}else{
	  lo[i] = d;
	}
      }
      buckets[d].clear();
    }
    init();
  }
  for(int i=0; i<q; i++){
    cout<<((queries[i].a==queries[i].b) ? 0 : ans[i]) <<'\n';
  }
  return 0;
}
