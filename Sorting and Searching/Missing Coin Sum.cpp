#include<bits/stdc++.h>
using namespace std;
int main(){
  ios_base:: sync_with_stdio(0); cin.tie(0);
  int n; cin>>n;
  vector<int> in(n); for(auto &i:in)cin>>i;
  sort(in.begin(), in.end());
  long long ans=1;
  for(int x : in){
	if(x>ans) break;
	ans+=x;
  }
  cout<<ans<<'\n';
  return 0;
}
