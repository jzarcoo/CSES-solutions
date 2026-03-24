#include<bits/stdc++.h>
using namespace std;
const int INF = INT_MAX;
int n, k;
int get(int f, int i){
  cout << "SF"[f] <<' '<< i << endl;
  cout.flush();
  int x; cin>>x;
  return x;
}
int bs(int l, int r){
  while(l<=r){
	int m = l + (r-l)/2;
	auto f = [&](int sm, int b)->int{
	  return (sm <= 0) ? INF : ((sm<=n) ? get(b,sm) : -INF);
	};
	int cF = f(m,1), nF = f(m+1,1);
	int cS = f(k-m,0), nS = f(k-m+1,0);
	if (cF >= nS && cS >= nF)
	  return min(cF, cS);
	if (cF < nS)
	  r = m - 1;
	else
	  l = m + 1;
  }
  return -1;
}
int main(){
  ios_base::sync_with_stdio(0); cin.tie(0);
  cin>>n>>k;
  int ans = bs(max(0,k-n), min(k,n));
  cout << "! "<< ans<<endl;
  return 0;
}
