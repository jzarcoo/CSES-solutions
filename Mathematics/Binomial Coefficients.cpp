#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MX = 1e6;
const int MOD = 1e9 + 7;
ll fact[MX+1], inv[MX+1];
ll binpow(ll a, ll b){
  ll res = 1;
  while(b){
	if (b&1) res = res * a % MOD;
	a = a * a % MOD;
	b >>= 1;
  }
  return res;
}
void build(){
  fact[0]=1;
  for(int i=1; i<=MX; i++){
	fact[i] = i * fact[i-1] % MOD;
	// inv[i] = binpow(fact[i], MOD-2);
  }
  inv[MX]= binpow(fact[MX], MOD - 2);
  for(int i = MX; i >= 1; i--){
	inv[i-1]= inv[i] * i % MOD;
  }
}
ll comb(ll n, ll k){
  return fact[n] * inv[k] % MOD * inv[n-k] % MOD;
}
void solve(){
  ll n, k; cin>>n>>k;
  cout << comb(n, k) << '\n';
}
int main(){
  ios_base::sync_with_stdio(false); cin.tie(nullptr);
  build();
  int t; cin>>t;
  while(t--) solve();
  return 0;
}
