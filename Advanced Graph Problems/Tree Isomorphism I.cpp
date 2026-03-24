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

map<vector<int>, int> mp;
int id=0;
int dfs(vvi &g, int v=0, int p=-1){
  vi c;
  for(int t : g[v])
	if(t!=p)
	  c.pb(dfs(g, t, v));
  sort(all(c));
  if (!mp.count(c))
	mp[c] = ++id;
  return mp[c];
}
void solve() {
  int n, x, y; cin>>n;
  vvi tree1(n), tree2(n);
  FOR(i,0,n-1){
	int a, b; cin>>a>>b;--a,--b;
	tree1[a].pb(b);
	tree1[b].pb(a);
  }
  FOR(i,0,n-1){
	int a, b; cin>>a>>b;--a,--b;
	tree2[a].pb(b);
	tree2[b].pb(a);
  }
  x = dfs(tree1);
  y = dfs(tree2);
  cout << ((x==y) ? "YES\n" : "NO\n");
}

int main() {
    fastIO();
    int t; cin >> t;
    while(t--)
	  solve();
    return 0;
}

