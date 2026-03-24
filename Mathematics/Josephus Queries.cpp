#include<bits/stdc++.h>
using namespace std;
int josephus(int n, int k){
  if (n==1) return 1;
  int r = (n+1)/2;
  if(k<=r) return (2*k>n) ? 1 : 2*k;
  return 2 * josephus(n/2,k-r) + ((n&1) ? +1 : -1);
}
int main(){
  ios_base::sync_with_stdio(false); cin.tie(nullptr);
  int q; cin>>q;
  while(q--){
	int n, k; cin>>n>>k;
	cout<<josephus(n,k)<<'\n';
  }
  return 0;
}
