#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
typedef vector<ll> vll;
typedef vector<vll> vvll;
#define fi first
#define se second
#define pb push_back
#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(),v.rend()
#define rz(n) resize(n)
#define sz(a) (int)(a.size())
#define fori(i,a,n) for(int i = a; i < n; i++)
#define endl '\n'
const int MOD = 1e9+7;
const int INF = INT_MAX;
const long long LLINF = LLONG_MAX;
const double EPS = DBL_EPSILON;
const long double PI = acosl(-1.0L);
#define cmp [](auto &a, auto &b) { return a.se < b.se; }
#define print(v) for(auto &i : v) {cout << i << ' ';} cout << endl;
#define cinv(v) for(auto &i : v) {cin >> i;}
void fastIO() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    // cout << fixed << setprecision();
}
ll n, ans=1;
vll arr;
void solve() {
  map<ll, ll> freq;
  ll j=0;
  fori(i,0,n){
	++freq[arr[i]];
	while(freq[arr[i]] == 2){
	  --freq[arr[j++]];
	}
	ans = max(ans, i-j+1);
  }
}

int main() {
    fastIO();
	cin>>n; arr.rz(n);
	cinv(arr);
	solve();
	cout<<ans<<endl;
    return 0;
}
