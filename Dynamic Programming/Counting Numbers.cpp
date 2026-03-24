#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MX=18;
const int D = 10;
ll dp[MX+1][2][D][2];
ll cnt(string s){
  int n = s.size();
  memset(dp, -1, sizeof dp);
  function<ll(int, bool, int, bool)> f = [&](int pos, bool tight, int prev, bool lz) -> ll{
	if (pos==n) return 1;
	ll &res = dp[pos][tight][prev][lz];
	if(res != -1) return res;
	res = 0;
	int limit = tight ? (s[pos]- '0') : 9;
	for(int digit=0; digit<=limit; ++digit){
	  if (digit == prev  && lz == 0) continue;
	  bool nextTight = tight && (digit == limit);
	  bool nxtlz = lz && (digit == 0);
	  res += f(pos+1, nextTight, digit, nxtlz);
	}
    return res;
  };
  return f(0, 1, 0, 1);
}
int main(){
  ios_base::sync_with_stdio(0);cin.tie(0);
  ll a,b; cin>>a>>b;
  cout << cnt(to_string(b)) - cnt(to_string(a-1))<<'\n';
  return 0;
}
