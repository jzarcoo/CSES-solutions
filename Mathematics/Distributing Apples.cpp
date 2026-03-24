#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD =1e9+7;
const int MX = 2*(1e6+1);
ll fact[MX], inv[MX];
ll binpow(ll b, ll e){
  ll ans=1;
  while(e){
	if (e & 1) ans = (ans * b) % MOD;
	b = (b * b)%MOD;
	e>>=1;
  }
  return ans;
}
void build(){
  fact[0] = inv[0] = 1;
  for(int i=1;i<MX;i++){
	fact[i] = (i * fact[i-1])%MOD;
	inv[i] = binpow(fact[i], MOD-2);
  }
}
ll comb(ll n, ll k){
  return fact[n] * inv[k] % MOD * inv[n-k] % MOD;
}
int main(){
  ios_base::sync_with_stdio(false); cin.tie(nullptr);
  build();
  ll n, m; cin>>n>>m;
  cout<<comb(n-1+m,m)<<'\n';
  return 0;
}
