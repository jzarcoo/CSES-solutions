#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1e9+7;
const ll N=500;
ll dp[2*N][2*N];
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n, k;
    cin>>n>>k;
    if(k>2*n-1){
        cout << 0 <<'\n';
        return 0;
    }
    
    dp[1][1] = 1;
    for(int i=0; i<2*n; i++)
        dp[i][0] = 1;

    for(int i=2; i<2*n; i++){
        ll squ = (i&1) ? i / 4 * 2 + 1 : (i-1)/4 * 2 + 2;
        //cout << i << " i, s " << squ << '\n';
        for(int j=1; j<=k; j++){
            ll s = squ - (j-1);
            dp[i][j] = (dp[i-2][j] + (dp[i-2][j-1] * s) % MOD) % MOD;
        }
    }

    ll r = 0;

    for(int i=0; i<=k; i++){
        ll m = (dp[2*n-1][i] * dp[2*n-2][k-i]) % MOD;
        r = (r+m) % MOD;
    }

    cout <<r<<'\n';
    
}
