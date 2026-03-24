#include<bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
const int R[]{2,2,1,1,-1,-1,-2,-2};
const int C[]{1,-1,2,-2,2,-2,1,-1};
int main(){
  ios_base::sync_with_stdio(0); cin.tie(0);
  int n; cin>>n;
  vector<vi> v(n, vi(n, -1));
  queue<array<int,3>> q;
  q.push({0,0,0});
  v[0][0]=0;
  while(!q.empty()){
	auto[x,y,d] = q.front(); q.pop();
	for(int i=0; i<8; i++){
	  int r = x+R[i], c=y+C[i], l =d+1;
	  if(r<0 || c<0 || r>=n || c>=n || v[r][c] != -1)
		continue;
	  v[r][c]=l;
	  q.push({r,c,l});
	}
  }
  for(int i=0; i<n;i++){
	for(int j=0; j<n;j++){
	  cout<<v[i][j]<<' ';
	}
	cout<<'\n';
  }
  return 0;
}
