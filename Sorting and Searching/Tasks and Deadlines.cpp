#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define fori(i,a,b) for(int i=a;i<b;i++)
void solve(){
  ll n; cin>>n;
  priority_queue<pair<ll,ll>> pq;
  fori(i,0,n){
    ll a, d; cin>>a>>d;
    pq.push({-a, d});
  }
  ll total = 0;
  ll start=0;
  while(!pq.empty()){
    auto [a, d] = pq.top(); pq.pop();
    a*=-1;
    total += d-(start+a);
    start += a;
  }
  cout<<total<<'\n';
}
int main(){
  ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
  solve();
  return 0;
}
