#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
int l=1, r=1e9;
int main(){
  ios_base::sync_with_stdio(0); cin.tie(0);
  while(l<r){
	int m = l + (r-l)/2;
	cout << "? "<<m<<endl;
	cout.flush();
	string s; cin>>s;
	if (s=="YES") l = m + 1;
	else r = m;
  }
  cout<< "! "<<r<<endl;
  return 0;
}
