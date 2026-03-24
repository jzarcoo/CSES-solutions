#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
  ios_base::sync_with_stdio(0); cin.tie(0);
  ll n, x; cin>>n>>x;
  vector<int> w(n); for(auto &i:w) cin>>i;
  ll N = 1<<n;
  vector<pair<int,ll>> dp(N, {n + 1, 0});
  dp[0] = {1,0};
  for(ll mask=1; mask < N; mask++){
	for(int bit=0; bit<n; bit++){
	  if (mask & (1<<bit)){
		auto prev = dp[mask^(1<<bit)];
		if (prev.second + w[bit] <= x){
		  prev.second += w[bit];
		}else{
		  prev.first += 1;
		  prev.second = w[bit];
		}
		dp[mask] = min(dp[mask], prev);
	  }
	}
  }
  cout<<dp[N-1].first<<'\n';
  return 0;
}
