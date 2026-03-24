#include<bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
#define fori(i,a,b) for(int i=a; i<b;i++)
int main(){
  ios_base::sync_with_stdio(false);cin.tie(nullptr);
  int n, k; cin>>n>>k;
  vi arr(n); for(auto &i: arr) cin>>i;
  vi freq(k+1);
  set<int> missing; fori(i,0,k+1) missing.insert(i);
  fori(i,1,n+1){
	int x = arr[i-1];
	if (i < k && x <= k){
	  freq[x]++;
	  missing.erase(x);
	}
	if (i>=k){
	  if (x <= k){
		freq[x]++;
		missing.erase(x);
	  }
	  cout << *missing.begin() << ' ';
	  int out = arr[i-k];
	  if (out <= k && --freq[out] == 0) missing.insert(out);
	}
  }
  return 0;
}

