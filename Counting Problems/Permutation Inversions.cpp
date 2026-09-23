#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD=1e9+7;
int n, k;
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin>>n>>k;
    vector<vector<ll>> dp(n+1, vector<ll>(k+1));
    dp[0][0] = 1;
    for(int len=1; len<=n; len++){
        vector<ll> prefix(k+1);
        prefix[0] = dp[len-1][0];
        for(int inv=1; inv<=k; inv++){
            prefix[inv] = (prefix[inv-1] + dp[len-1][inv]) % MOD;
        }
        for(int inv=0; inv<=k; inv++){
            // suma dp[len-1][inv - 0] a dp[len-1][inv - (len-1)]
            ll &cur = dp[len][inv] = prefix[inv];
            if(inv >= len){
                cur -= prefix[inv-len];
                if(cur<0)cur+= MOD;
            }
        }
    }
    cout << dp[n][k] << '\n';
}
