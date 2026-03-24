#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

typedef long long ll;
typedef vector<ll> vll;
#define FOR(i,a,b) for(int i=a;i<=b;i++)

const int MOD = 1e9+7;

ll n, m;

int main(){
  ios_base::sync_with_stdio(false); cin.tie(nullptr);
  cin>>n>>m;
  vll v(n+1);
  FOR(i,1,n){
	cin>>v[i];
  }
  vector<vll> dp(n+1, vll(m+1, 0));
  if (v[1]==0){
	FOR(i,1,m){
	  dp[1][i]=1;
	}
  }else{
	dp[1][v[1]]=1;
  }
  FOR(i,2,n){
	if (v[i] == 0) {
	  FOR(j,1,m){
		dp[i][j] = dp[i-1][j];
		dp[i][j] = (dp[i][j] + dp[i-1][j-1]) % MOD;
		if (j + 1 <= m)
		  dp[i][j] = (dp[i][j] + dp[i-1][j+1]) % MOD;
	  }
	} else {
	  dp[i][v[i]] = dp[i-1][v[i]];
	  dp[i][v[i]] = (dp[i][v[i]] + dp[i-1][v[i]-1]) % MOD;
	  if (v[i] + 1 <= m)
		dp[i][v[i]] = (dp[i][v[i]] + dp[i-1][v[i]+1]) % MOD;
	}
  }
  ll ans=0;
  FOR(i,1,m) ans = (ans + dp[n][i]) % MOD;
  cout<<ans<<'\n';
  return 0;
}
