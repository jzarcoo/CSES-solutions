#include <bits/stdc++.h>
typedef long long ll;
#define all(a)a.begin(),a.end()
using namespace std;
int main() {
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n;cin>>n;
  vector<ll> in(n); for(auto &i: in) cin>>i;
  ll m = *max_element(all(in));
  ll s = accumulate(all(in), 0LL);
  s-=m;
  ll ans = (m < s) ? s+m : 2*m;
  cout<<ans<<endl;
  return 0;
}

