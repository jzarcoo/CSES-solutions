#include<bits/stdc++.h>
using namespace std;
int main(){
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n, a=0; cin>>n;
  while(n){
	n/=5;
	a+=n;
  }
  cout<<a<<endl;
  return 0;
}
