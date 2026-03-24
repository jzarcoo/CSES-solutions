#include <bits/stdc++.h>
using namespace std;
int main(){
  ios_base::sync_with_stdio(0); cin.tie(0);
  int n, k; cin>>n>>k;
  long long x,a,b,c; cin>>x>>a>>b>>c;
  vector<int> w(k);
  int ans = 0, xr = 0;
  for(int i=0; i<n; i++){
	if (i<k){
	  w[i]=x;
	  xr^=x;
	  if (i==k-1) ans^=xr;
	}else {
	  xr ^= w[i%k];
	  w[i%k] = x;
	  xr ^= w[i%k];
	  ans ^= xr;
	}
	x = (a*x + b) %c;
  }
  cout<<ans<<'\n';
  return 0;
}
