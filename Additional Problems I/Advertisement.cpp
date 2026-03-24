#include<bits/stdc++.h>
using namespace std;
int main(){
  ios_base::sync_with_stdio(0); cin.tie(0);
  int n; cin>>n;
  long long ans = 0;
  vector<int> h(n); for(auto &i: h) cin>>i;
  stack<int> s;
  for(int i=0; i<n; ++i){
	while(!s.empty() && h[s.top()] >= h[i]) {
	  int rem = s.top(); s.pop();
	  int w = s.empty() ? i : i - s.top() - 1;
	  ans = max(ans, 1LL*w*h[rem]);
	}
	s.push(i);
  }
  while(!s.empty()){
	int rem = s.top(); s.pop();
	int w = s.empty() ? n : n - s.top() - 1;
	ans = max(ans, 1LL* w * h[rem]);
  }
  cout<<ans<<'\n';
  return 0;
}
