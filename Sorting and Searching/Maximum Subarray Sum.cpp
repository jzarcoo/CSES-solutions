#include<bits/stdc++.h>
using namespace std;
using ll = long long;
void solve(){
  // int n; cin>>n;--n;
  // ll mx; cin>>mx;
  // ll curr=mx;
  // while(n--){
  // 	ll x; cin>>x;
  // 	curr = max(x, curr+x);
  // 	mx = max(mx, curr);
  // }
  // cout << mx<<endl;
  int n; cin>>n;
  vector<ll> a(n); for(auto &i:a)cin>>i;
  ll ans = a[0], sum = 0;
  for (int r = 0; r < n; ++r) {
	sum += a[r];
    ans = max(ans, sum);
    sum = max(sum, 0LL);
  }
  cout<<ans<<'\n';
}
int main(){
  ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
  solve();
  return 0;
}
