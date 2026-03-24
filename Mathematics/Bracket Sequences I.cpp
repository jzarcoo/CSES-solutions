#include<iostream>
#include<vector>
using namespace std;
typedef long long ll;
const ll m=1e9+7;
ll binpow(ll a, ll b){
  ll res=1;
  while(b){
	if (b&1) res = (res*a)%m;
	a = (a*a)%m;
	b>>=1;
  }
  return res;
}
int main(){
  ios_base::sync_with_stdio(false);cin.tie(nullptr);
  ll t; cin>>t;
  if (t%2==1) {
	cout<<0<<'\n';
	return 0;
  }
  vector<ll> fact(t+1), inv(t+1);
  fact[0]=inv[0]=1;
  for(int i=1; i<=t;i++){
	fact[i] = (fact[i-1]*i)%m;
	inv[i]=binpow(fact[i],m-2);
  }
  //t>>=1;						
  
  cout << fact[t] * inv[t>>1] % m * inv[(t>>1)+1] % m <<'\n';
  
  return 0;
}

