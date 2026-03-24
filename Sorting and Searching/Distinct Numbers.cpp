#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
// pair
typedef pair<int,int> ii;
typedef pair<ll,ll> pll;
// vector
typedef vector<int> vi;
typedef vector<char> vc; // vector char
typedef vector<ll> vll;
typedef vector<ii> vii;
typedef vector<vi> vvi;
typedef vector<vii> vvii;
// queue
typedef queue<int> qi;
typedef queue<ii> qii;
typedef queue<ll> qll;
typedef queue<ld> qld;
// dequeue
typedef deque<int> di;
typedef deque<ii> dii;
typedef deque<ll> dll;
typedef deque<ld> dld;
// stack
typedef stack<int> si;
typedef stack<ll> sll;
typedef stack<ld> sld;
// priority queue
typedef priority_queue<int> pqi;
typedef priority_queue<ll> pqll;
typedef priority_queue<ld> pqld;
// miselaneos
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
    ll n; cin >> n;
    set<ll> s;
    ll x; 
    fori(i,0,n) {
        cin >> x;
        s.insert(x);
    }
    cout << sz(s) << endl;
 
}
 
int main() {
    fastIO();
//    setIO();
    solve();
    return 0;
}