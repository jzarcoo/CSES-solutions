#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1e9+7;
ll binpow(ll a, ll b){ // a^b
  ll ans = 1;
  while (b){ // b>0
    if (b&1){ // b%2==1
      ans = (ans*a) % MOD;
    }
    a = (a*a) % MOD;
    b>>=1; // b/=2
  }
  return ans;
}
 
int main(){
  ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);// esto es para leer y escribir más rapido
  int t; cin>>t;
  while(t--){
    ll a, b; cin>>a>>b;
    cout << binpow(a,b)<<'\n';
  }
  return 0;
}