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
const int DIM = 8;
void fastIO() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
}
string board[DIM];
bool blocked[DIM][DIM];
int ans=0;
int queens[DIM]; // rows
bool diag1[2*DIM];
bool diag2[2*DIM];
void solve() {
    do {
        bool valid=true;
        fori(c,0,DIM){
            if(blocked[queens[c]][c]) {
                valid =false;
                break;
            }
        }
        if (!valid) continue;
        memset(diag1, false, sizeof(diag1));
        fori(c,0,DIM){
            if (diag1[c + queens[c]]){
                valid =false;
                break;
            }
            diag1[queens[c] + c] = true;
        }
        if (!valid) continue;
        memset(diag2, false, sizeof(diag2));
        fori(c,0,DIM){
            if (diag2[queens[c] - c + DIM - 1]){
                valid =false;
                break;
            }
            diag2[queens[c] - c + DIM - 1] = true;
        }
        if (!valid) continue;
        ++ans;
    } while(next_permutation(queens, queens+DIM));
}

int main() {
    fastIO();
    fori(r,0,DIM){
        cin>>board[r];
        fori(c,0,DIM){
            blocked[r][c] = board[r][c] == '*';
        }
    }
    iota(queens, queens + DIM, 0);
    solve();
    cout << ans << endl;
    return 0;
}