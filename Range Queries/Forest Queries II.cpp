#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vl;
typedef vector<vl> vvl;
#define fori(i,a,b) for(int i=a; i<b;i++)
struct BIT2D{
  vvl bit;
  int n, m;
  BIT2D(int n, int m) : n(n), m(m){
	bit.assign(n+1,vl(m+1,0));
  }
  ll query(int x, int y){
	ll sum=0;
	for(int i=x+1; i>0; i-= i&-i){
	  for(int j=y+1;j>0; j-= j & -j){
		sum += bit[i][j];
	  }
	}
	return sum;
  }
  void update(ll x, ll y, ll delta){
	for(int i=x+1; i<=n; i+= i&-i){
	  for(int j=y+1; j<=m; j+=j &-j){
		bit[i][j] += delta;
	  }
	}
  }
  ll rect(int y1, int x1, int y2, int x2){
	return query(y2,x2)
	  - query(y1-1, x2)
	  - query(y2, x1-1)
	  + query(y1-1,x1-1);
  }
};
int main(){
  ios_base::sync_with_stdio(false);cin.tie(nullptr);
  int n, q; cin>>n>>q;
  BIT2D bit(n,n);
  vector<string> g(n);
  fori(i,0,n){
	cin>>g[i];
	fori(j,0,n){
	  if (g[i][j]=='*') bit.update(i,j,1);
	}
  }
  while(q--){
	int o; cin>>o;
	if (o==1){
	  int y, x; cin>>y>>x; --y,--x;
	  int d = (g[y][x] == '*') ? -1 : 1;
	  g[y][x] = (d==1) ? '*' : '.';
	  bit.update(y, x, d);
	}else{
	  int y1,x1,y2,x2; cin>>y1>>x1>>y2>>x2;
	  cout << bit.rect(y1-1,x1-1,y2-1,x2-1) << '\n';
	}
  }
  return 0;
}
