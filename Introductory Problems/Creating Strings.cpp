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
#define print(v) for(auto &i : v) {cout << i << '\n';} 
#define cinv(v) for(auto &i : v) {cin >> i;}
void fastIO() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    // cout << fixed << setprecision();
}
string s;
vector<string> ans;
void solve() {
    sort(all(s));
    do{
        ans.pb(s);
    }while(next_permutation(all(s)));
    cout<<sz(ans)<<endl;
    print(ans);
}
int main() {
    fastIO();
    cin>>s;
    solve();
    return 0;
}