#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n, m; cin>>n>>m;
  multiset<int> s;
  while(n--){
	int x; cin>>x;
	s.insert(x);
  }
  while(m--){
	int x; cin>>x;
	auto it = s.upper_bound(x);
	if(it == s.begin()){
	  cout<<-1<<endl;
	  continue;
	}
	--it;
	cout << *it<<endl;
	s.erase(it);
  }
  return 0;
}

