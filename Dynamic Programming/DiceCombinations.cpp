#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1e9+7;
const int MAXN = 1e6+1;
ll n;
ll maneras[MAXN];
// ll cuenta(ll x){
//   if(x==0) return 1;
//   ll &ans = maneras[x];
//   if(ans!=-1) return ans;
//   ans = 0;
//   for(int i=1; i<=6; i++){
// 	if(x-i>=0)
// 	  ans = (ans + cuenta(x-i)) % MOD;
//   }
//   return ans;
// }
void solve(){
  maneras[0]=1;
  for(int i=0; i<MAXN; i++){
	for(int c = 1; c <= 6; c++){
	  if(i+c<MAXN)
		maneras[i+c] = (maneras[i] + maneras[i+c]) % MOD;
	  // if(i-c>=0)
	  // 	maneras[i] = (maneras[i] + maneras[i-c]) % MOD;
	}
  }
  cout<<maneras[n]<<endl;
}
int main() {
  ios_base::sync_with_stdio(0); cin.tie(0);
  cin>>n;
  solve();
  // memset(maneras, -1, sizeof maneras);
  // cout << cuenta(n) << endl;
  return 0;
}
