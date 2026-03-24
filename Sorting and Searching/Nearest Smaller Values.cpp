#include<bits/stdc++.h>
using namespace std;
using ll=long long;
void solve(){
  ll n, i=0; cin>>n;
  stack<pair<ll,ll>> st;
  while(i++ < n){
	ll x; cin>>x;
	while(!st.empty() && st.top().second >= x) st.pop();
	cout<< (st.empty() ? 0 : st.top().first) << ' ';
	st.push({i,x});
  }
}
int main(){
  ios_base::sync_with_stdio(false); cin.tie(nullptr);
  solve();
  return 0;
}
