#include<bits/stdc++.h>
using namespace std;
const long long INF = LLONG_MAX;
int main (){
  ios_base::sync_with_stdio(0);cin.tie(0);
  long long x,y, u1=-INF,l1=INF,u2=-INF,l2=INF;
  int n; cin>>n;
  while(n--){
	cin>>x>>y;
	u1 = max(u1, x+y);
	l1 = min(l1, x+y);
	u2 = max(u2,x-y);
	l2 = min(l2,x-y);
	cout<<max(u2-l2,u1-l1)<<'\n';
  }
  return 0;
}
