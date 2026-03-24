#include<bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef vector<vi> vvi;
#define pb push_back
#define rz resize
#define FOR(i,a,b) for(int i=a; i<b;i++)
#define FORE(i,a,b) for(int i=a; i<=b;i++)
const int INF = INT_MAX;
int n, m, k;
vvi g;
vi d, match;
bool bfs(){
  queue<int> q;
  FORE(at,1,n){
	if (!match[at]){
	  q.push(at);
	  d[at]=0;
	}else{
	  d[at]=INF;
	}
  }
  d[0]=INF;
  while(!q.empty()){
	int at=q.front();q.pop();
	if (d[at] >= d[0]) continue;
	for(int to: g[at]){
	  if (d[match[to]]==INF){
		d[match[to]]=d[at]+1;
		q.push(match[to]);
	  }
	}
  }
  return d[0]!=INF;
}
bool dfs(int at){
  if (at==0) return true;
  for(int to : g[at]){
	if (d[match[to]] == d[at] + 1 && dfs(match[to])){
	  match[to]=at;
	  match[at]=to;
	  return true;
	}
  }
  d[at]=INF;
  return false;
}
int main(){
  ios_base::sync_with_stdio(0);cin.tie(0);
  cin>>n>>m>>k;
  g.rz(n+m+1), d.rz(n+m+1), match.rz(n+m+1);
  FOR(i,0,k){
	int a, b; cin>> a>>b; b+=n;
	g[a].pb(b);
	g[b].pb(a);
  }
  int c=0;
  while(bfs()){
	FORE(at, 1, n) if (!match[at] && dfs(at)) c++;
  }
  cout<<c<<'\n';
  FORE(at,1,n) if (match[at]) cout << at <<' '<<match[at]-n<<'\n';
  return 0;
}
