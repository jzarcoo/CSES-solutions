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
const int N=2e5+5;
struct FT{
    vll bit; int n;
    FT(int _n){
        n = _n;
        bit.rz(n+1, 0);
    }
    void upd(int p, ll d){
        for(; p<=n; p += p & -p){
            bit[p] += d;
        }
    }

    ll query(int p){
        ll s = 0;
        for(; p; p -= p & -p){
            s+=bit[p];
        }
        return s;
    }
    ll query(int l, int r){
        return query(r) - query(l-1);
    }
    void clean(){
        fill(all(bit), 0);
    }
};
int n, a[N];
FT* tree;
vi vals;

void solve() {
    tree = new FT(sz(vals));
    ll ans = 0;
    vll inv(n);
    FOR(i,0,n){
        inv[i] = tree->query(a[i], sz(vals));
        tree->upd(a[i], 1);
    }
    tree->clean();
    ROFE(i, n-1, 0){
        ans += min(inv[i],tree->query(a[i], sz(vals)) );
        tree->upd(a[i], 1);
    }
    cout <<ans<<endl;
}

int main() {
    fastIO();
    cin>>n;
    FOR(i,0,n){
        cin>>a[i];
        vals.pb(a[i]);
    }
    sort(all(vals));
    vals.erase(unique(all(vals)), vals.end());
    FOR(i,0,n){
        a[i] = lower_bound(all(vals), a[i]) - vals.begin() + 1;
    }
    solve();
    return 0;
}
