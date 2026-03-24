#include<bits/stdc++.h>
using namespace std;
int main(){
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n; cin>>n;
  vector<long long> v(n); 
  long long s=0, ans=0;
  v[0]=1;
  for(int i=0,x; i<n;i++){
    cin>>x;
	s+=x;
	++v[((s%n)+n)%n];
  }
  for(long long x : v)ans+= x * (x-1) / 2;
  cout<<ans<<endl;
  return 0;
}
