#include<bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n, m; cin>>n>>m;
    vector<vector<int>> compatible(1 << n, vector<int>(1 << n));
    vector<vector<long long>> ways(m + 2, vector<long long>(1 << n));
    for (int i = 0; i < (1 << n); i++) {
        for (int j = 0; j < (1 << n); j++) {
            int inactive = (~i) & (~j);
            int last = -1;
            bool ok = true;
            for (int b = 0; b < n; b++) {
                if (inactive & (1 << b)) {
                    if (last == -1) {
                        last = b;
                    } 
                } else {
                    if (last != -1) {
                        ok &= (b - last) % 2 == 0;
                        last = -1;
                    }
                }
            }
            if (last != -1) {
                ok &= (n - last) % 2 == 0;
            }
            compatible[i][j] = ok;
        }
    }
    ways[1][0] = 1;
    for (int col = 2; col <= m + 1; col++) {
        for (int mask = 0; mask < (1 << n); mask++) {
            int complement = (~mask) & ((1 << n) - 1);
            for (int sub = complement; ; sub = (sub - 1) & complement) {
                ways[col][mask] += ways[col - 1][sub] * compatible[mask][sub];
                if (sub == 0) break;
            }
            ways[col][mask] %= MOD;
        }
    }
    cout << ways[m + 1][0] << '\n';
}
