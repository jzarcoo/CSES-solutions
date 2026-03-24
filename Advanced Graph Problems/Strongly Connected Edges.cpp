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
const int INF = INT_MAX;
const ll LLINF = LLONG_MAX;
const double EPS = DBL_EPSILON;
const long double PI = acosl(-1.0L);
#define print(v) for(auto &i : v) {cout << i << ' ';} cout << endl;
#define cinv(v) for(auto &i : v) {cin >> i;}
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
void solve() {
  int n, m; cin>>n>>m;
  vvii adj(n);
  vi tin(n,-1), low(n,-1), edges_used(m);
  string orient; orient.rz(m);
  vii edges(m);
  FOR(i,0,m){
	int a,b; cin>>a>>b;--a,--b;
	adj[a].pb({b,i});
	adj[b].pb({a,i});
	edges[i]={a,b};
  }
  int comp_cnt=0, bridge_cnt=0, timer=0;
  function<void(int)> dfs = [&](int v){
	low[v]=tin[v]=timer++;
	for(auto [to, i] : adj[v]){
	  if(edges_used[i]) continue;
	  edges_used[i]=1;
	  orient[i] = v == edges[i].fi ? '>' : '<';
	  if(tin[to]!=-1) low[v]=min(low[v],tin[to]);
	  else{
		dfs(to);
		low[v] = min(low[v],low[to]);
		if (low[to]>tin[v]) bridge_cnt++;
	  }
	}
  };
  FOR(v,0,n){
	if(tin[v]==-1){
	  comp_cnt++;
	  dfs(v);
	}
  }
  if (bridge_cnt>0 || comp_cnt>1){
	cout<<"IMPOSSIBLE\n";
	return;
  }
  FOR(i,0,m){
	auto [a, b] = edges[i];
    if (orient[i]=='<') swap(a,b);
	cout<<a+1<<' '<<b+1<<endl;
  }
}

int main() {
  fastIO();
  solve();
  return 0;
}

