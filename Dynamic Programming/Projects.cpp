#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
struct P{
  int ini, fin, re;
};
int main(){
  ios_base::sync_with_stdio(0); cin.tie(0);
  int n; cin>>n;
  vector<P> v;
  for(int i=0;i<n;i++){
	int a,b,c; cin>>a>>b>>c;
	v.push_back(P{a,b,c});
  }
  sort(v.begin(), v.end(), [&](const P &a, const P &b){
	return a.fin < b.fin;
  });
  vi fines(n);for(int i=0;i<n;i++)fines[i] = v[i].fin;
  vector<ll> dp(n);
  for(int i=0; i<n; i++){
	ll tomar = v[i].re;
    int idx = lower_bound(fines.begin(), fines.end(), v[i].ini) - fines.begin() - 1;
	if (idx>=0)
	  tomar += dp[idx];
	dp[i] = max(tomar, i>0 ? dp[i-1] : 0LL);
  }
  cout<<dp[n-1]<<'\n';
  return 0;
}
