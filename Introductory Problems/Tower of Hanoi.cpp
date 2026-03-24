#include<bits/stdc++.h>
using namespace std;
#define pb push_back
int n;
vector<pair<int,int>> moves;
void hanoi(const int &d, const int &source=1, const int &aux=2, const int &destination=3){
  if (d==1){
	moves.pb({source, destination});
	return;
  }
  hanoi(d-1, source, destination, aux);
  moves.pb({source, destination});
  hanoi(d-1, aux, source, destination);
}
void solve(){
  hanoi(n);
  cout<<moves.size()<<'\n';
  for(auto [from, to] : moves) cout<<from<<' '<<to<<'\n';
}
int main(){
  ios_base::sync_with_stdio(false); cin.tie(nullptr);
  cin>>n;
  solve();
  return 0;
}
