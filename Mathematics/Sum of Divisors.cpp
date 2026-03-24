#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const ll MOD=1e9+7;
const ll TWO_INV = 5e8+4;
ll sum(ll a, ll b){
  return ((((b-a+1)%MOD)*((a+b)%MOD)%MOD)*TWO_INV%MOD);
}
int main(){
  ios_base::sync_with_stdio(false); cin.tie(nullptr);
  ll n; cin>>n;
  ll at=1, ans = 0;
  while(at<=n){
	ll add_amt = n / at;
	ll last_same = min(n, n / add_amt);
	ans = (ans + add_amt * sum(at, last_same))%MOD;
	at = last_same + 1;
  }
  cout<<ans<<endl;
  return 0;
}
