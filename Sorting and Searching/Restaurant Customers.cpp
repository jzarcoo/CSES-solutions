#include<bits/stdc++.h>
using namespace std;
int main(){
  ios_base::sync_with_stdio(0);cin.tie(0);
  vector<pair<int, int>> v;
  int n, a, b; cin>>n;
  while(n--){
	cin>>a>>b;
	v.emplace_back(a,1);
	v.emplace_back(b,-1);
  }
  sort(v.begin(), v.end());
  int cnt=0, m=INT_MIN;
  for(int i=0; i<v.size();++i){
	auto &[_, t] = v[i];
	if (t==1){
	  ++cnt;
	}else{
	  --cnt;
	}
	m = max(cnt, m);
  }
  cout<<m<<'\n';
  return 0;
}
