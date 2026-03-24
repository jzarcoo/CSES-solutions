#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n, t; cin>>n>>t;
  vector<int> a(n); for(auto &i:a)cin>>i;
  ll l = 1, r = 1LL * t * *min_element(begin(a), end(a));
  auto ok = [&](ll m)->bool{
	ll p = 0;
	for(int x : a){
	  p += m /x;
	  if (p>=t) return 1;
	}
	return 0;
  };
  while (r - l > 1) {
	ll m = l + (r-l) /2;
    if (ok(m)) {
        r = m; 
    } else {
        l = m; 
    }
  }
  cout<< r <<endl;
  return 0;
}
