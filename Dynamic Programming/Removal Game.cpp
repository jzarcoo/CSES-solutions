#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 5005;
int n;
ll arr[N], dp[N][N], pre[N];
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin>>n;
    for(int i=1; i<=n; i++){
        cin>>arr[i];
        dp[i][i] = arr[i];
        pre[i] = pre[i-1] + arr[i];
    }

    for(int len = 2; len <= n; len++){
        for(int i=1; i+len-1<=n; i++){
            int j = i+len-1;
            
            ll s = pre[j] - pre[i-1];
            
            ll fi = s - dp[i+1][j];
            ll se = s - dp[i][j-1];

            dp[i][j] = max(fi, se);
        }
    }

    cout << dp[1][n] << '\n';
    
}
