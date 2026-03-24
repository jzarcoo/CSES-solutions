#include<bits/stdc++.h>
using namespace std;
int main(){
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n, m; cin>>n>>m;
  vector<pair<int,int>> g;
  while(m--){
	int a,b; cin>>a>>b;
	if (a>b) swap(a,b);
	g.push_back({a,b});
  }
  for(auto [a,b] : g) cout<<a<<' '<<b<<'\n';
  return 0;
}
