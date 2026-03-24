#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef vector<int> vi;
typedef vector<vi> vvi;
#define FOR(i,a,b) for(int i=a;i<b; i++)
#define ROF(i,a,b) for(int i=a;i>b; i--)
#define FORE(i,a,b) for(int i=a;i<=b; i++)
#define ROFE(i,a,b) for(int i=a;i>=b; i--)
int main(){
  ios_base::sync_with_stdio(false);cin.tie(nullptr);
  int n; cin>>n;
  vll v(n); for(auto &i: v) cin>>i;
  vll preffix(n+1,0);
  partial_sum(v.begin(), v.end(), preffix.begin()+1);
  vvll dp(n,vll(n));
  vvi opt(n,vi(n));
  auto C = [&](int i, int j){
	// Implement cost function C
	return preffix[j+1] - preffix[i];
  };
  FOR(i,0,n){
	opt[i][i] = i;
	// Initialize dp[i][i] according to the problem
	dp[i][i] = 0;
  }
  ROFE(i, n-2, 0){
	FOR(j,i+1,n){
	  ll mn = LLONG_MAX;
	  ll cost = C(i,j);
	  FORE(k, opt[i][j-1], min(j-1, opt[i+1][j])){
		ll val = dp[i][k] + dp[k+1][j] + cost;
		if (mn >= val){
		  opt[i][j] = k;
		  mn = val;
		}
	  }
   	  dp[i][j] = mn;
	}
  }
  cout << dp[0][n-1] <<'\n';
  return 0;
}
