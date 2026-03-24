#include <bits/stdc++.h>
using namespace std;
int main(){
  ios_base::sync_with_stdio(0); cin.tie(0);
  int n; cin>>n;
  vector<int> v(n); for(auto &i:v)cin>>i;
  int l=0;
  long long ans=0;
  multiset<int> s;
  for(int r=0;r<n;r++){
	while(s.count(v[r]))
	  s.erase(v[l++]);
	s.insert(v[r]);
	ans += r-l+1;
  }
  cout<<ans<<'\n';
  return 0;
}
