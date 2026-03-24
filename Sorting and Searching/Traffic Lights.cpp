#include<bits/stdc++.h>
using namespace std;
int x, n;
int main(){
  ios_base::sync_with_stdio(0); cin.tie(0);
  cin>>x>>n;
  multiset<int> ms{x}; // ans
  set<int> s{0,x}; // poste
  while(n--){
	int p; cin>>p;
	auto it2 = s.upper_bound(p);
	auto it1 = it2;
	it1--;
	ms.erase(ms.find(*it2-*it1));
	ms.insert(*it2-p);
	ms.insert(p-*it1);
	s.insert(p);
	auto ans = ms.end();
	--ans;
	cout<<*ans<< ' ';
  }
  
  return 0;
}
