#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define re(v) for(auto &i:v) cin>>i;
int n, x;
int main(){
  ios_base::sync_with_stdio(0); cin.tie(0);
  cin>>n>>x;
  vector<int> w(n),v(n),k(n);
  vector<ll> f(x+1);
  re(w);re(v);re(k);
  vector<pair<ll,ll>> a;
  for(int i=0;i<n;i++){
	int c = 1;
	while(k[i]>0){
	  int t = min(c, k[i]);
	  a.emplace_back(1LL*t*w[i],1LL*t*v[i]);
	  k[i]-=t;
	  c<<=1;
	}
  }
  for (auto &[w, v]:a)
	for(int j=x; j>=w;j--)
	  f[j] = max(f[j], f[j-w]+v);
  cout<<f[x];
  return 0;
}
