#include<bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
int n,m, l;
vi hotels, st;
void qu(int x, int v=1, int tl=0, int tr=l-1){
  if (st[v] < x) {
	cout << "0 ";
	return ;	  
  }
  if (tl==tr) {
	st[v]-=x;
	cout<<tl+1<<' ';
	return;
  }
  int tm = tl + ((tr-tl)/2);
  if (st[2*v] >= x)
	qu(x,2*v, tl, tm);
  else
	qu(x, 2*v+1, tm+1, tr);
  st[v] = max(st[2*v], st[2*v+1]);
}
int main(){
  ios_base::sync_with_stdio(0); cin.tie(0);
  cin>>n>>m;
  hotels.resize(n); for(auto &i:hotels) cin>>i;
  l = 1;
  while(l<n) l<<=1;
  st.assign(2*l, INT_MIN);
  for(int i=0; i<n ;i++) st[l+i] = hotels[i];
  for(int i=l-1; i>0; i--) st[i] =max(st[2*i], st[2*i+1]);
  while(m--){
	int x; cin>>x;
	qu(x);
  }
  return 0;
}
