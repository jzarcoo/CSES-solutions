#include<bits/stdc++.h>
using namespace std;
int main(){
  ios_base::sync_with_stdio(0);cin.tie(0);
  int k; cin>>k;
  for(long long i = 1, ans,y; i<=k;++i){
	y=i*i;
	ans = (y*(y-1))/2-(4*(i-1)*(i-2));
	cout<<ans<<endl;
  }
  return 0;
}
