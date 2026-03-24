#include <bits/stdc++.h>
using namespace std;
int main(){
  ios_base::sync_with_stdio(0); cin.tie(0);
  int n; cin>>n;
  vector<int> v;
  int l = INT_MAX, r=0;
  for(int i=0; i<n;i++){
	int x; cin>>x;
	v.push_back(x);
	l = min(l, x);
	r += x;
  }
  vector<bool> can(r+1);
  can[0]=1;
  for(int i=0; i<n; i++){
	//cout <<i<<endl;
	for(int j = r; j>=v[i]; j--){
	  can[j] = can[j] || can[j-v[i]];
	  //if(can[j]) cout<<j<<' ';
	}
	//cout<<endl;
  }
  vector<int> a;
  for(int i=l; i<=r;i++){
	if(can[i]) a.push_back(i);;
  }
  cout<<a.size()<<endl;
  for(int x: a)cout<<x<<' ';
  return 0;
}
