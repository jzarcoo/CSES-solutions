#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vll;
typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef vector<vii> vvii;
const ll INF = LLONG_MAX;
vll dijkstra(int v, vvii &g){
  vll d(g.size(), INF);
  d[v] = 0;
  auto cmp = [&](ll i, ll j){
	if(d[i]==d[j])return i<j;
	return d[i] < d[j];
  };
  set<ll, decltype(cmp)> s(cmp);
  s.insert(v);
  while(!s.empty()){
	int at = *s.begin(); s.erase(s.begin());
	for(auto [to, w] : g[at]){
	  if (d[at] + w < d[to]){
		s.erase(to);
		d[to] = d[at] + w;
		s.insert(to);
	  }
	}
  }
  return d;
}
int main(){
  ios_base::sync_with_stdio(false); cin.tie(nullptr);
  int n, m; cin>>n>>m;
  vvii graph(n);
  for(int i=0;i<m;i++){
	int a, b, c; cin>>a>>b>>c;
	graph[--a].push_back({--b,c});
  }
  for(ll x : dijkstra(0, graph)){
	cout<< x <<' ';
  }
  return 0;
}
