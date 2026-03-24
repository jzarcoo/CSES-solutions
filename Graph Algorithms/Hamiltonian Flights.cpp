#include<bits/stdc++.h>
using namespace std;
const int N = 20;
const int MASK = 1<<N;
const int MOD = 1e9+7;
int n, m;
vector<int> radj[N];
long long dp[MASK][N];
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin>>n>>m;
    for(int i=0; i<m; i++){
        int a, b; cin>>a>>b; --a,--b;
        radj[b].emplace_back(a);
    }
    dp[1][0] = 1;
    for(int s=2; s<(1<<n); s++){
        if (!(s & 1)) continue;
        if (s & (1<<(n-1)) && s != (1<<n) - 1) continue;
        for (int i=0; i<n; i++)
            if (s & (1<<i))
                for(int v : radj[i])
                    if (s & (1<<v))
                        dp[s][i] = (dp[s][i] + dp[s-(1<<i)][v]) % MOD; 
    }
    cout<<dp[(1<<n)-1][n-1];
}
