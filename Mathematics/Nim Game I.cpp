#include<iostream>
using namespace std;
typedef long long ll;
int main(){
  ios_base::sync_with_stdio(false);cin.tie(nullptr);
  int t; cin>>t;
  while(t--){
	ll n; cin>>n;
	ll ans=0;
	while(n--){
	  ll x; cin>>x;
	  ans^=x;
	}
	cout<< ((ans) ? "first\n" : "second\n");
  }
  return 0;
}
