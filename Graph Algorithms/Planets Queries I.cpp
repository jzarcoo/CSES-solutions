#include<bits/stdc++.h>
using namespace std;
int n, q;
const int k = 30;
const int MX = 2e5+5;
int p[MX][k];
int main(){
  ios_base::sync_with_stdio(0);cin.tie(0);
  cin>>n>>q;
  for(int i=1; i<=n; i++)
    cin>>p[i][0];
  for(int l=1; l<k; l++)
	for(int i=1; i<=n; i++)
	  p[i][l]=p[p[i][l-1]][l-1];
  while(q--){
	int x, l; cin>>x>>l;
	for(int i=0; i<k;i++)
	  if (l & (1 << i))
		x = p[x][i];
	cout<<x<<'\n'; 
  }
  return 0;
}
