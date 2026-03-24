#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef complex<ll> P;
int main(){
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n,x,y; cin>>n;
  vector<P> p;
  while(n--){
	cin>>x>>y;
	p.emplace_back(x,y);
  }
  ll ans=0;
  n=p.size();
  for(int i=0;i<n;++i){
	ans += (conj(p[i%n])*p[(i+1)%n]).imag();
  }
  cout<<labs(ans);
  return 0;
}
