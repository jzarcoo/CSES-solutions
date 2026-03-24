#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int MOD = 1e9+7;
ll binpow(ll a, ll b, ll M){
  ll ans=1;
  while(b){
	if (b&1) ans = (ans * a) % M;
	a = (a * a) % M;
	b>>=1;
  }
  return ans;
}
int main(){
  ios_base::sync_with_stdio(false); cin.tie(nullptr);
  int t; cin>>t;
  while(t--){
	ll a, b, c; cin>>a>>b>>c;
	ll exp = binpow(b, c, MOD - 1);
	cout << binpow(a, exp, MOD) <<'\n';
  }
  return 0;
}
