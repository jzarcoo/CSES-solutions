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
int n, i=0;
vi pre, in, ans;
unordered_map<int,int> mp;

void solve(int pl, int pr, int il, int ir) {
  if (pr < pl || ir < il) return ;
  int root = pre[pl];
  ans[n-1-i] = root; ++i;
  int id = mp[root];
  int left = id - il;
  solve(pl+left+1, pr, id+1, ir);
  solve(pl+1, pl+left, il, id-1);
}

int main() {
    fastIO();
	cin>>n;
    in.rz(n); pre.rz(n); ans.rz(n);
	cinv(pre); cinv(in);
	FOR(i,0,n){
	  mp[in[i]]=i;
	}
	solve(0,n-1,0,n-1);
	print(ans);
    return 0;
}
