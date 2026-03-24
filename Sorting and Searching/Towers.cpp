#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vll;
#define pb push_back
#define re(v) for(auto &i: v) cin>>i;
#define FOR(i,a,b) for(int i=a; i<b;i++)
int lis(vll &arr){
  vll aux;
  for(int x : arr){
	if (aux.empty() || x >= aux.back()) aux.pb(x);
	else {
	  auto it = upper_bound(aux.begin(), aux.end(), x);
	  *it = x;
	}
  }
  return aux.size();
}
int main(){
  ios_base::sync_with_stdio(0); cin.tie(0);
  ll N; cin>>N;
  vll arr(N); re(arr);
  cout<<lis(arr)<<'\n';
  return 0;
}
