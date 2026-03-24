#include<bits/stdc++.h>
using namespace std;
const int M = 1e6;
int num[M+1];
int main(){
  ios_base::sync_with_stdio(0); cin.tie(0);
  int n,x,cnt; cin>>n;
  while(n--){
    cin>>x;
	++num[x];
  }
  for(int g=M; g>0; --g){
	cnt=0;
	for(int i=g; i<=M; i+=g)
	  cnt += num[i];
	if(cnt >= 2){
	  cout<<g<<'\n';
	  break;
	}
  }
  return 0;
}

