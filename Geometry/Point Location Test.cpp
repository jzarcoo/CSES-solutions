#include<bits/stdc++.h>
using namespace std;
using ll=long long;
struct point2d{
  ll x, y;
  point2d () {}
  point2d(const ll& x, ll& y) : x(x), y(y) {}
  point2d& operator-=(const point2d &t) {
	x-=t.x; y-=t.y;
	return *this;
  }
};
ll cross(const point2d &a, const point2d &b){
  return 1LL * a.x * b.y - 1LL * a.y * b.x;
}
void solve(){
  point2d a,b,c;
  cin>>a.x>>a.y>>b.x>>b.y>>c.x>>c.y;
  b-=a; c-=a;
  ll ans = cross(b,c);
  if (ans==0){
	cout << "TOUCH" << '\n';
  }else if (ans < 0){
	cout << "RIGHT" << '\n';
  } else {
	cout << "LEFT" << '\n';
  }
}
int main(){
  ios_base::sync_with_stdio(false); cin.tie(nullptr);
  int t; cin>>t;
  while (t--) solve();
  return 0;
}
