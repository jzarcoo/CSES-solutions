#include<bits/stdc++.h>
using namespace std;
int main(){
  ios_base::sync_with_stdio(0); cin.tie(0);
  int n,m,k; cin>>n>>m>>k;
  vector<int> a(n), d(m);
  for(auto &i:a)cin>>i;
  for(auto &i:d)cin>>i;
  sort(a.begin(), a.end());
  sort(d.begin(), d.end());
  int ans=0;
  int i=0,j=0;
  while(i<n && j<m){
	if (abs(a[i]-d[j]) <= k){
	  ++i,++j,++ans;
	}else if (a[i] > d[j]){
	  ++j;
	}else{
	  i++;
	}
  }
  cout<<ans<<'\n';
  return 0;
}
