#include<bits/stdc++.h>
using namespace std;
long long r,c,ans;
void solve(){
  if (r>c){
	if(r&1){
	  ans = (r-1)*(r-1)+c;
	}else{
	  ans = r*r-c+1;
	}
  }else{
	if (c&1){
	  ans = c * c - r + 1;
	}else{
	  ans = (c-1)*(c-1)+r;
	}
  }
}
int main(){
  ios_base::sync_with_stdio(0);cin.tie(0);
  int t;cin>>t;
  while(t--){
	cin>>r>>c;
	solve();
	cout<<ans<<'\n';
  }
  return 0;
}
