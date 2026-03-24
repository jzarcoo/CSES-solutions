#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MX = 1e6;
const int MOD = 1e9+7;
const int ALF = 26;
int chars[ALF];
ll fact[MX+1], inv[MX+1];
ll binpow(ll a, ll b){
  ll ans=1;
  while(b){
	if (b&1) ans = a*ans %MOD;
	a = a * a %MOD;
	b>>=1;
  }
  return ans;
}
void build(){
  fact[0]=1;
  for(int i=1; i<=MX;i++){
	fact[i] = i * fact[i-1] % MOD;
	// inv[i] = binpow(fact[i], MOD-2);
  }
  inv[MX] = binpow(fact[MX], MOD-2);
  for(int i=MX; i>=1; i--){
	inv[i-1]=i*inv[i] %MOD;
  }
}
int main(){
  ios_base::sync_with_stdio(0); cin.tie(0);
  build();
  string s; cin>>s;
  for(char c: s){
	chars[c-'a']++;
  }
  ll ans = fact[s.size()];
  for(int c : chars){
    if (c > 0){
	  ans  = ans * inv[c] % MOD;
	}
  }
  cout<<ans<<'\n';
  return 0;
}
