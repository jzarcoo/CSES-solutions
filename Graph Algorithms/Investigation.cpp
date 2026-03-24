#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vll;
typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef vector<vii> vvii;
const ll INF = LLONG_MAX;
const int MOD = 1e9+7;
int s = 0, t;
void dijkstra(vvii &g, vll &d, int n){
  d[s]=0;
  priority_queue<pair<ll,ll>> pq;
  pq.push({0,s});
  vll num(n,0), mini(n,0), maxi(n,0);
  num[s]=1;
  while(!pq.empty()){
    auto [d_v, v]= pq.top(); pq.pop();
	d_v *= -1;
	if (d_v != d[v]) continue;
	for(auto [to, len] : g[v]){
	  ll sum = d_v + len;
	  if (sum < d[to]){
		num[to] = num[v];
		mini[to] = mini[v]+1;
		maxi[to] = maxi[v]+1;
		d[to] = sum;
		pq.push({-d[to], to});
	  }else if (d[to] == sum){
	    num[to] = (num[to] + num[v]) % MOD;
		mini[to] = min(mini[to], mini[v]+1);
		maxi[to] = max(maxi[to], maxi[v]+1);
	  }
	}
  }
  cout << d[t] << ' '<< num[t] <<' '<<mini[t]<<' '<<maxi[t]<<'\n';
}
int main(){
  ios_base::sync_with_stdio(false); cin.tie(nullptr);
  int n, m; cin>>n>>m;
  t = n-1;
  vvii graph(n);
  for(int i=0;i<m;i++){
	int a, b, c; cin>>a>>b>>c;
	graph[--a].push_back({--b,c});
  }
  vll d(n, INF);
  dijkstra(graph, d, n);
  return 0;
}

