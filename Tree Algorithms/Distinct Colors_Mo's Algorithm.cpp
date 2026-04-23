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

const int N = 2e5+5;

struct Query{
    int l, r, i;
};

vi g[N], vals;
int n,  diff = 0, tin[N], timer = 0, euler[N], color[N], len;
vector<Query> queries;

void dfs(int v, int p){
    tin[v] = ++timer;
    euler[tin[v]] = color[v];
    for(int c : g[v]){
        if(c==p) continue;
        dfs(c, v);
    }
    queries.pb(Query{tin[v], timer, v});
}

void add(int pos){
    if(++color[euler[pos]] == 1) ++diff;
}

void remove(int pos){
    if(--color[euler[pos]] == 0) --diff;
}

void solve() {
    dfs(1, 0);
    memset(color, 0, sizeof color);
    len = (int) sqrt(n + .0) + 1;
    reverse(all(queries));
    sort(all(queries), [&](const Query &a, const Query &b){
        if(a.l/len != b.l / len)
            return make_pair(a.l, a.r) < make_pair(b.l, b.r);
        return (a.l / len & 1) ? (a.r < b.r) : (a.r > b.r);
    });
    vals.rz(n, -1);
    int l = 1, r = 0;
    for(Query &q : queries){
        while(l > q.l){
            add(--l);
        }
        while(r < q.r){
            add(++r);
        }
        while(l < q.l){
            remove(l++);
        }
        while(r > q.r){
            remove(r--);
        }
        vals[q.i - 1] = diff;
    }
    print(vals);
}

int main() {
    fastIO();
    cin>>n;
    FORE(i,1,n){
        cin>>color[i];
        vals.pb(color[i]);
    }
    sort(all(vals));
    vals.erase(unique(all(vals)), vals.end());
    FORE(i,1,n){
        color[i] = lower_bound(all(vals), color[i]) - vals.begin() + 1;
    }    
    FOR(i,1,n){
        int a, b; cin>>a>>b;
        g[a].pb(b);
        g[b].pb(a);
    }
    solve();
    return 0;
}
