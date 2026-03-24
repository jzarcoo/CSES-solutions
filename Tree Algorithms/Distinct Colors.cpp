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
}
ll n; 
vvll adj;
vll color, ans;
set<ll>* dfs(ll at=0, ll prev=-1) {
    set<ll>* s = new set{color[at]};
    for(ll &v : adj[at]){
        if (v==prev) continue;
        set<ll>* h = dfs(v, at);
        if (h->size()>s->size()) swap(s,h);
        for(ll x : *h) (*s).insert(x);
    }
    ans[at] = s->size();
    return s;
}
int main() {
    fastIO();
    cin>>n;
    color.rz(n); cinv(color);
    adj.rz(n); ans.rz(n);
    ll a, b;
    fori(i,0,n-1){
        cin>>a>>b;--a,--b;
        adj[a].pb(b);
        adj[b].pb(a);
    }
    dfs();
    print(ans);
    return 0;
}