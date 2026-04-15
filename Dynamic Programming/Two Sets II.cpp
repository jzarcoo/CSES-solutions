#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod = 1e9+7;
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n; cin>>n;
    ll s = (1LL * n * (n+1)) / 2;
    if(s&1){
        cout << 0;
        return 0;
    }
    ll t = s/2;
    vector<ll> dp(t+1, 0); dp[0]=1;
    for(int i=1; i< n; i++){
        for(int j = t; j>=i; j--){
            dp[j] = (dp[j] + dp[j-i]) % mod;
        }
    }
    ll res = dp[t];
    cout << res;
}
    
