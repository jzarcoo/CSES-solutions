#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef complex<ll> P;
#define X real()
#define Y imag()
#define rep(i,a,b) for(int i=a;i<b;++i)
int n;
ll i, b;
vector<P> poly;
ll cross(P &a, P &b){
  return (conj(a)*b).Y;
}
void solve(){
  ll a = 0;
  rep(i,0,n){
	a += cross(poly[i], poly[(i+1)%n]);
  }
  a = labs(a) / 2;
  b = 0;
  rep(i,0,n){
	P d = poly[(i+1)%n] - poly[i];
	b += gcd(labs(d.X), labs(d.Y));
  }
  i = a - b / 2 + 1;
}
int main(){
  ios_base::sync_with_stdio(0);cin.tie(0);
  cin>>n;
  rep(i,0,n){
	int x,y; cin>>x>>y;
	poly.emplace_back(x,y);
  }
  solve();
  cout<<i<<' '<<b<<endl;
  return 0;
}
