#include<bits/stdc++.h>
using namespace std;
int main(){
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n,a,b; cin>>n;
  while(n--){
	cin>>a>>b;
	cout << (((2*b-a)%3 || (2*a-b)%3 || (2*b-a)<0 || (2*a-b)<0) ? "NO\n" : "YES\n");
  }
  return 0;
}
