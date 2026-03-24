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
bool ckmin(int &a, int b){return a>b? a=b,1 : 0;}
bool ckmax(int &a, int b){return a<b? a=b,1 : 0;}
void fastIO() {
  ios_base::sync_with_stdio(false); cin.tie(nullptr);
}
void solve() {
  int n; cin>>n;
  map<vi, int> mp;
  int id = 0;
  vvi f(n), s(n);
  vi degf(n), degs(n);
  FOR(i,0,n-1){
	int a,b;cin>>a>>b;--a,--b;
	f[a].pb(b);
	f[b].pb(a);
	++degf[a], ++degf[b];
  }
  FOR(i,0,n-1){
	int a,b;cin>>a>>b;--a,--b;
	s[a].pb(b);
	s[b].pb(a);
	++degs[a], ++degs[b];
  }
  function<vi(vvi&, vi&)> get_center = [&](vvi &g, vi &d){
	vi leaves;
    FOR(i,0,n)
	  if(d[i]<=1)
		leaves.pb(i);
	int cnt = sz(leaves);
	while(cnt < n){
	  vi new_leaves;
	  for(int l : leaves)
		for(int v : g[l])
		  if(--d[v]==1)
			new_leaves.pb(v);
	  cnt += sz(new_leaves);
	  leaves = new_leaves;
	}
	return leaves;
  };
  function<int(vvi &, int, int)> encode = [&](vvi &g, int v, int p){
	vi arr;
	for(int c: g[v])
	  if (c!=p)
		arr.pb(encode(g,c,v));
	sort(all(arr));
	if(!mp.count(arr))
	  mp[arr]=++id;
	return mp[arr];
  };
  vi fc = get_center(f,degf), sc = get_center(s,degs);
  int x = encode(f, fc[0], -1);
  for(int c : sc){
	if (x == encode(s, c, -1)){
	  cout <<"YES\n";
	  return;
	}
  }
  cout<<"NO\n";
}

int main() {
  fastIO();
  int t; cin >> t;
  while(t--)
	solve();
  return 0;
}
