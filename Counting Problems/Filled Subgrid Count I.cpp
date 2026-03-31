#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=3000;
ll dp[N+1][N+1];
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n, k; cin>>n>>k;
    vector<string> grid(n);
    for(int i=0; i<n; i++){
        cin>>grid[i];
    }
    for(int i=0; i<k; i++){
        memset(dp,0, sizeof dp);
        ll ans = 0;
        for(int r=1; r<=n; r++){
            for(int c=1; c<=n; c++){
                if(grid[r-1][c-1]-'A' != i) continue;
                dp[r][c] = 1 + min({dp[r-1][c],
                                      dp[r][c-1],
                                      dp[r-1][c-1]});
                ans += dp[r][c];
                
            }
        }
        cout << ans << '\n';
    }
}

