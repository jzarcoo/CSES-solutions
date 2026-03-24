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
  // no importa el orden
  ll n,x;cin>>n>>x;
  vll coins(n); cinv(coins);
  vll dp(x+1);
  dp[0]=1;
  for(ll c:coins){
    for(ll i=c;i<=x;i++){
      dp[i] = (dp[i]+dp[i-c])%MOD;
    }
  }
  cout << dp[x]<<endl;
}

int main() {
    fastIO();
    // setIO();
    // int testCases;cin >> testCases;while( testCases-- ) {solve();}
    solve();
    return 0;
}
