#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
#define pb push_back
#define eb emplace_back
#define sz(a) (int) a.size()
#define rz resize
#define all(a) a.begin(), a.end()
struct Edge {
  int from, to;
  ll cap, flow=0;
  Edge(int from, int to, ll cap) : from(from), to(to), cap(cap) {}
};
struct Dinic{
  const ll FLOW_INF = LLONG_MAX;
  vector<Edge> edges;
  vvi adj;
  int n, m=0, s, t;
  vi level, ptr;
  queue<int> q;
  Dinic(int n, int s, int t) : n(n), s(s), t(t) {
	adj.rz(n);
	level.rz(n);
	ptr.rz(n);
  }
  void add_edge(int from, int to, ll cap){ // from != to
	edges.eb(from, to, cap);
	edges.eb(to, from, cap); // 0
	adj[from].pb(m++);
	adj[to].pb(m++);
  }
  bool bfs(){
	fill(all(level), n+1);
	level[s] = 0;
	q.push(s);
	while(!q.empty()){
	  int at = q.front(); q.pop();
	  for(int id : adj[at]){
		Edge &e = edges[id];
		if (e.cap > e.flow && level[e.from] + 1 < level[e.to]){
		  level[e.to] = level[e.from] + 1;
		  q.push(e.to);
		}
	  }
	}
	return level[t] != n+1;
  }
  ll dfs(int v, ll pushed){
	if (v==t || pushed==0) return pushed;
	for(int &i = ptr[v]; i< sz(adj[v]); i++){
	  int id = adj[v][i], to = edges[id].to;
	  if (level[v]+1 == level[to])
		if (ll flow = dfs(to, min(pushed, edges[id].cap - edges[id].flow))){
		  edges[id].flow += flow;
		  edges[id^1].flow -= flow;
		  return flow;
		}
	}
	return 0;
  }
  ll max_flow(){
	ll tot_flow = 0;
	while(bfs()){
	  fill(all(ptr), 0);
	  while(ll pushed = dfs(s, FLOW_INF))
		tot_flow += pushed;
	}
	return tot_flow;
  }
};
int main(){
  ios_base::sync_with_stdio(0); cin.tie(0);
  int n, m; cin>>n>>m;
  Dinic d(n, 0, n-1);
  while(m--){
	int a, b; cin>>a>>b; --a,--b;
	d.add_edge(a,b,1);
  }
  cout<<d.max_flow()<<'\n';
  for(Edge &e : d.edges)
	if(d.level[e.from] != n+1 && d.level[e.to]==n+1)
	  cout<<e.from+1<<' '<<e.to+1<<'\n';
  return 0;
}
