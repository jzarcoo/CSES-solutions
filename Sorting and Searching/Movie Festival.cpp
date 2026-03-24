#include<bits/stdc++.h>
using namespace std;
int main(){
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n,s,e,ans=0,ini=0;
  cin>>n;
  vector<pair<int,int>> v;
  while(n--){
    cin>>s>>e;
    v.emplace_back(e,s);
  }
  sort(begin(v), end(v));
  for(int i=0; i<(int)v.size();++i){
    if (ini <= v[i].second){
      ++ans;
      ini = v[i].first;
    }
  }
  cout<<ans<<endl;
  return 0;
}

