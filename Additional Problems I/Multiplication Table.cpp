#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
  ios_base::sync_with_stdio(0); cin.tie(0);
  ll n; cin>>n;
  ll l = -1, r= n*n;
  ll t = (r + 1) / 2;
  while(r-l>1){
	ll m = l + (r-l)/2, c = 0;
	for(int i=1;i<=n;++i){
	  if (m/i == 0) break;
	  c += min(n, m /i);
	}
	if (c>=t)r=m;
	else l=m;
  }
  cout << r << endl;
  return 0;
}
