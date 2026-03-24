#include<bits/stdc++.h>
using namespace std;
using ll = long long;
void solve(){
  int n; cin>>n;
  ll sum=0;
  vector<int> durations;
  for(int i=0; i<n; i++){
    int a, d; cin>>a>>d;
    sum += d;
    durations.push_back(a);
  }
  sort(durations.begin(), durations.end());
  for(int i = 0; i < n; i++){
    sum -= 1LL * durations[i] * (n - i);
  }
  cout<<sum<<'\n';
}
int main(){
  ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
  solve();
  return 0;
}
