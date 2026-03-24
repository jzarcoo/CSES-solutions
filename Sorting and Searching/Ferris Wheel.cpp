#include<bits/stdc++.h>
using namespace std;
int main(){
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n, m; cin>>n>>m;
  vector<int> kid(n), left(n,0); for(auto &i: kid)cin>>i;
  sort(kid.begin(), kid.end());
  int l=0, r=n-1;
  int ans=0;
  while(l<r)
	if (kid[l]+kid[r]<=m){
	  left[r--]=left[l++]=1;
	  ans++;
	}else
	  r--;
  if(!left[l] && kid[l]<=m) left[l]=1, ans++;
  cout<< ans + n - accumulate(left.begin(), left.end(), 0);
  return 0;								 
}
