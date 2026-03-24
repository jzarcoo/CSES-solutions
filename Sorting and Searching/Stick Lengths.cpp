#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(0);cin.tie(0);
  long long n;cin>>n;
  vector<long long> v(n);
  for(auto &i: v)cin>>i;
  sort(v.begin(), v.end());
  long long m = v[n / 2];
  long long ans=0;
  for(long long x :v){
	ans+=abs(x-m);
  }
  cout<<ans<<endl;
  return 0;
}

