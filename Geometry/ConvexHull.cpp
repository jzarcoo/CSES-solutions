#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ii = pair<ll,ll>;
using vii = vector<ii>;
#define all(a) a.begin(), a.end()
#define sz(a) (int)a.size()
#define se second
#define fi first
ll cross(const ii &O, const ii &A, const ii &B) {
    return (A.fi - O.fi) * (B.se - O.se)
         - (A.se - O.se) * (B.fi  - O.fi);
}
vii convex_hull(vii &pts) {
    pts.erase(unique(all(pts)), pts.end());
    int n = sz(pts), k = 0;
    if (n <= 1) return pts;
    sort(all(pts));
    vii H(2*n);
    for (int i = 0; i < n; i++) { // Lower hull
        while (k >= 2 && cross(H[k-2], H[k-1], pts[i]) < 0) k--; // <= 0 elimina también colineales
        H[k++] = pts[i];
    }
    for (int i = n-2, t = k+1; i >= 0; i--) { // Upper hull
        while (k >= t && cross(H[k-2], H[k-1], pts[i]) < 0) k--; // <= 0 elimina también colineales
        H[k++] = pts[i];
    }
    H.resize(k-1); // quita el duplicado final
    return H;
}
int main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);
    int n; cin >> n;
    vii pts(n); for (auto &p : pts) cin >> p.fi >> p.se;
    vii hull = convex_hull(pts);
    cout << sz(hull) << '\n';
    for (auto &p : hull)
        cout << p.fi << " " << p.se << '\n';
    return 0;
}
