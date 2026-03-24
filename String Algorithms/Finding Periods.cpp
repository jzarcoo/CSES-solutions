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
    // cout << fixed << setprecision();
}
// void setIO() {
//     #ifndef ONLINE_JUDGE
//         freopen("input.txt", "r", stdin);
//         freopen("output.txt", "w", stdout);
//     #endif
// }

void solve() {
  string s; cin>>s;
  int m = sz(s);
  vi lps(m);
  int i=1, len=0;
  while(i<m){
	if(s[i]==s[len]) lps[i++]=++len;
	else if (len) len = lps[len-1];
	else i++;
  }
  int k = lps[m-1];
  vi ans={m};
  while(k>0){
	ans.pb(m-k);
	k = lps[k-1];
  }
  sort(all(ans));
  print(ans);
}

int main() {
    fastIO();
	solve();
    return 0;
}

