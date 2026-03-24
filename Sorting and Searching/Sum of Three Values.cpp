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
void fastIO() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}
void solve() {
    ll n, t; cin >> n >> t;
    vector<pll> v(n);
    fori(i,0,n) {
        cin >> v[i].fi;
        v[i].se = i+1;
    }
    sort(all(v));
    fori(i,0,n) {
        ll l = i+1, r = n-1;
        ll t2 = t - v[i].fi;
        while (l < r) {
            if (v[l].fi + v[r].fi < t2) {
                l++;
            } else if (v[l].fi + v[r].fi > t2) {
                r--;
            } else {
                cout << v[i].se << ' ' << v[l].se << ' ' << v[r].se << endl;
                return;
            }
        }
    }
    cout << "IMPOSSIBLE" << endl;
    
}
 
int main() {
    fastIO();
//    setIO();
    // int testCases;cin >> testCases;while( testCases-- ) {solve();}
    solve();
    return 0;
}