#include<bits/stdc++.h>
using namespace std;
const int M = 1e6+1;
const int MOD = 1e9+7;
long long dp[2][M];
int main(){
  ios_base::sync_with_stdio(0);cin.tie(0);
  int t, n;cin>>t;
  dp[0][1]=1;
  dp[1][1]=1;
  for(int i=2; i<M; i++){
	dp[0][i] = ((dp[0][i-1]<<1) % MOD + dp[1][i-1]) % MOD;
	dp[1][i] = (dp[0][i-1] + (dp[1][i-1]<<2) % MOD) % MOD;
  }
  while(t--){
	cin>>n;
	cout<<(dp[0][n]+dp[1][n])%MOD<<'\n';
  }
  return 0;								 
}
