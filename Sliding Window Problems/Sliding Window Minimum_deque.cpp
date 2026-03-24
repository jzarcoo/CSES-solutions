#include <bits/stdc++.h>
using namespace std;
int main(){
  ios_base::sync_with_stdio(0); cin.tie(0);
  int n, k; cin>>n>>k;
  long long x,a,b,c; cin>>x>>a>>b>>c;
  deque<pair<int,int>> dq;
  int ans = 0;
  for(int i=0; i<n; i++){
	while(!dq.empty() && dq.back().first >= x) dq.pop_back();
	dq.push_back({x,i});
	if (dq.front().second <= i - k){
	  dq.pop_front();
	}
	if (i >= k - 1){
	  ans ^= dq.front().first;
	}
	x = (a * x + b) % c;
  }
  cout<<ans<<'\n';
  return 0;
}
