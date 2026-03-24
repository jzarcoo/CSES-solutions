#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vll;
typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef vector<vii> vvii;
typedef vector<int> vi;
typedef vector<vi> vvi;
#define fi first
#define se second
#define pb push_back
#define eb emplace_back
#define rz resize
#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(),v.rend()
#define sz(a) (int)(a.size())
#define FOR(i,a,n) for(int i = a; i < n; i++)
#define FORE(i,a,n) for(int i = a; i <= n; i++)
#define ROF(i,a,n) for(int i = a; i > n; i--)
#define ROFE(i,a,n) for(int i = a; i >= n; i--)
#define endl '\n'
const int MOD = 1e9+7;
const ll LLINF = LLONG_MAX;
const double EPS = DBL_EPSILON;
const long double PI = acosl(-1.0L);
#define print(v) for(auto &i : v) {cout << i << ' ';} cout << endl;
#define cinv(v) for(auto &i : v) {cin >> i;}
bool ckmin(int &a, int b){return a>b? a=b,1 : 0;}
bool ckmax(int &a, int b){return a<b? a=b,1 : 0;}
void fastIO() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    // cout << fixed << setprecision();
}
// void setIO() {
//     #ifndef ONLINE_JUDGE
//         freopen("input.txt", "r", stdin);
//         freopen("output.txt", "w", stdout);
//     #endif
// }
const int INF = 1e9;
template<int MN, int MM>
struct MCF {
  int N, M, S, T;
  int flow[MM*2], cap[MM*2], nx[MM*2], to[MM*2], cost[MM*2];
  int hd[MN], pi[MN], p[MN], d[MN], vis[MN];
  void init(int n, int s, int t){
	N=n,S=s,T=t;
	memset(hd,-1,sizeof hd);
	memset(flow,0,sizeof flow);
  }
  void adde1(int a, int b, int u, int c){
	nx[M]=hd[a], hd[a]=M;
	to[M]=b, cost[M]=c, cap[M]=u;
	M++;
  }
  void adde(int a, int b,int u, int c){
	adde1(a,b,u,c);
	adde1(b,a,0,-c);
  }
  void setpi(){
	//memset(pi,0x3e, sizeof pi);
	fill(pi,pi+N, INF);
	memset(vis,0,sizeof vis);
	queue<int> q({S});
	pi[S]=0;
	for(int n; !q.empty();){
	  n = q.front(); q.pop();
	  for(int id=hd[n], x;~id;id=nx[id]){
		if(cap[id]-flow[id]>0){
		  x=to[id];
		  if(ckmin(pi[x], pi[n]+cost[id]))
			assert(++vis[x]<=N), q.push(x);
		}
	  }
	}
  }
  struct state{
	int n,d;
	bool operator>(state o) const {return d>o.d;}
  };
  void dijk(){
	// memset(p, -1, N * sizeof p[0]);
	// memset(vis, 0, N*sizeof vis[0]);
	// memset(d, 0x3e, N* sizeof d[0]);
	fill(d, d + N, INF);
	fill(p, p + N, -1);
	memset(vis, 0, sizeof vis);
	priority_queue<state, vector<state>, greater<state>> pq;
	pq.push({S,0});
	d[S]=0;
	for(int n; !pq.empty();){
	  n=pq.top().n; pq.pop();
	  if(vis[n]) continue;
	  vis[n]=1;
	  for(int id = hd[n],x,w;~id;id=nx[id]){
		if(cap[id]-flow[id]>0){
		  x=to[id];
		  w=cost[id]+pi[n]-pi[x];
		  if(ckmin(d[x], w+d[n]))
			p[x]=id, pq.push({x,d[x]});
		}
	  }
	}
  }
  int mincost(int F){
	setpi();
	int C=0;
	while(F>0){
	  dijk();
	  if(d[T]==INF) return INF;
	  int c=d[T]+pi[T]-pi[S], f=F;
	  for(int x=T; x!=S; x=to[p[x]^1])
		ckmin(f, cap[p[x]]-flow[p[x]]);
	  C+=c*f;
	  for(int x=T; x!=S; x=to[p[x]^1]){
		flow[p[x]]+=f;
		flow[p[x]^1]-=f;
	  }
	  F-=f;
	  FOR(i,0,N)if (d[i]<INF) pi[i]+=d[i];
	}
	return C;
  }
};
void solve() {
  int n,m,k; cin>>n>>m>>k;
  MCF<505,2005> mcf;
  mcf.init(n+1,1,n);
  FOR(i,0,m){
	int a,b; cin>>a>>b;
	mcf.adde(a,b,1,1);
  }
  int ans = mcf.mincost(k);
  if (ans==INF){
	cout<<-1<<endl;
	return;
  }
  cout<<ans<<endl;
  FOR(i,0,k){
	vi p({1});
	int u=1;
	while(u!=n){
	  for(int id=mcf.hd[u]; ~id; id=mcf.nx[id]){
		if(mcf.cost[id]==1&&mcf.flow[id]==1){
		  mcf.flow[id]=0;
		  u=mcf.to[id];
		  p.pb(u);
		  break;
		}
	  }
	}
	cout<<sz(p)<<endl;
	print(p);
  }
}

int main() {
    fastIO();
	solve();
    return 0;
}
