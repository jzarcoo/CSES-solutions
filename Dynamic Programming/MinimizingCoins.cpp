#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> ii;
typedef pair<ll,ll> pll;
typedef vector<char> vc; 
typedef vector<bool> vb;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<ii> vii;
typedef vector<vi> vvi;
typedef vector<vii> vvii;
#define fi first
#define se second
#define pb push_back
#define pf push_front
#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(),v.rend()
#define sz(a) (int)(a.size())
#define fori(i,a,n) for(int i = a; i < n; i++)
#define endl '\n'
const int MOD = 1e9+7;
const int INF = INT_MAX;
const long long LLINF = LLONG_MAX;
const double EPS = DBL_EPSILON;
#define cmp [](auto &a, auto &b) { return a.se < b.se; }
#define print(v) for(auto &i : v) {cout << i << ' ';} cout << endl;
#define cinv(v) for(auto &i : v) {cin >> i;}
// min heap
#define minH(T) priority_queue<T, vector<T>, greater<T>>

void fastIO() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}
void setIO() {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
}

void solve() {
  ll n, t; cin>>n>>t;
  vll c(n); cinv(c);
  vll dp(t+1,INF);
  dp[0]=0;
  fori(i,1,t+1){
    for(ll j:c){
      if (i-j>=0){
	dp[i]=min(dp[i],1+dp[i-j]);
      }
    }
  }
  if (dp[t]==INF){
    cout << -1<<endl;
  }else{
    cout << dp[t]<<endl;
  }
}

int main() {
    fastIO();
    // setIO();
    // int testCases;cin >> testCases;while( testCases-- ) {solve();}
    solve();
    return 0;
}
