#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vll;
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
  vvi radj(n);
  vi out(n);
  FOR(i,0,m){
	int a, b; cin>>a>>b;--a,--b;
	radj[b].pb(a);
	out[a]++;
  }
  priority_queue<int> q;
  FOR(i,0,n) if (out[i]==0) q.push(i);
  vi ans;
  while(!q.empty()){
	int cur = q.top(); q.pop();;
	ans.pb(cur+1);
	for(int from : radj[cur])
	  if (--out[from]==0)
		q.push(from);
  }
  FOR(i,0,sz(ans)){
	cout<<ans[sz(ans)-1-i]<<' ';
  }
}

int main() {
    fastIO();
	solve();
    return 0;
}
