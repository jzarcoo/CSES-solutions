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
bool diag1[2*DIM];
bool diag2[2*DIM];
bool row_taken[DIM];
void bck(int c){
    if (c==DIM){
        ++ans;
        return;
    }
    fori(r,0,DIM){
        if (row_taken[r] || blocked[r][c] || diag1[r + c] || diag2[r - c + DIM - 1]) continue;
        row_taken[r] = true;
        diag1[r + c] = true;
        diag2[r - c + DIM - 1] = true;
        bck(c+1);
        diag1[r + c] = false;
        diag2[r - c + DIM - 1] = false;
        row_taken[r] = false;
    }
}

int main() {
    fastIO();
    fori(r,0,DIM){
        cin>>board[r];
        fori(c,0,DIM){
            blocked[r][c] = board[r][c] == '*';
        }
    }
    bck(0);
    cout << ans << endl;
    return 0;
}