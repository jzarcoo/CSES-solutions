#include<bits/stdc++.h>
using namespace std;
long long s,m, cnt=0;
int n;
void solve(){
  vector<int> f;
  int l=1, r=n;
  m = s>>1;
  while(cnt!=m){
	if(cnt+r<=m){
	  cnt+=r;
	  f.push_back(r--);
	}
	if(cnt+l<=m){
	  cnt+=l;
	  f.push_back(l++);
	}
  }
  cout<<"YES\n";
  cout<<f.size()<<'\n';
  for(int x:f)cout<<x<<' ';
  cout<<'\n';
  cout<<n-f.size()<<'\n';
  while(l<=r) cout<<l++<<' ';
}
int main(){
  ios_base::sync_with_stdio(0);cin.tie(0);
  cin>>n;
  s = (1LL* n*(n+1)) / 2;
  if (s&1){
	cout<<"NO\n";
  }else {
	solve();
  }
  return 0;
}
