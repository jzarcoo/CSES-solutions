#include<iostream>
#include<vector>
using namespace std;
typedef long long ll;
const ll m=1e9+7;
int main(){
  ios_base::sync_with_stdio(false);cin.tie(nullptr);
  ll t; cin>>t;
  if (t%2==1) {
	cout<<0<<'\n';
	return 0;
  }
  t>>=1;
  vector<ll> catalan(t+1);
  catalan[0]=catalan[1]=1;
  for( int i=2; i<=t;i++){
	catalan[i]=0;
	for(int j=0;j<i;j++){
	  catalan[i] += (catalan[j]*catalan[i-j-1])%m;
	  if (catalan[i]>=m) catalan[i]-=m;
	}
  }
  cout << catalan[t]<<'\n';
  return 0;
}

