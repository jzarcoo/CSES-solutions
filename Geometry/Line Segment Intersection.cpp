#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef complex<ll> P;
#define X real()
#define Y imag()
ll cross(P a, P b){
  return (conj(a)*b).Y;
}
P p[4];
struct R{
  int x1,x2,y1,y2;
} r[2];
bool intersect(R a, R b) {
  return !(a.x2 < b.x1 || b.x2 < a.x1 || a.y2 < b.y1 || b.y2 < a.y1);
}
int point_location(P a, P b, P c){
  b-=a, c-=a;
  ll ans = cross(b,c);
  return ans==0 ? 0 : ans<0 ? -1 : 1;
}
bool check(){
  if(point_location(p[0],p[1],p[2]) * point_location(p[0],p[1],p[3]) > 0)
	return 0;
  if(point_location(p[2],p[3],p[0]) * point_location(p[2],p[3],p[1]) > 0)
	return 0;
  return 1;
}
void solve(){
  if(!intersect(r[0], r[1])){
	cout<<"NO\n";
  }else{
	cout<< (check() ? "YES\n" : "NO\n");
  }
}
int main(){
  ios_base::sync_with_stdio(0);cin.tie(0);
  int t,x,y,i;cin>>t;
  while(t--){
	for(i=0; i<4;i++){
	  cin>>x>>y; p[i]={x,y};
	}
	r[0].x1 = min(p[0].X, p[1].X), r[0].x2 = max(p[0].X, p[1].X);
	r[0].y1 = min(p[0].Y, p[1].Y), r[0].y2 = max(p[0].Y, p[1].Y);
	r[1].x1 = min(p[2].X, p[3].X), r[1].x2 = max(p[2].X, p[3].X);
	r[1].y1 = min(p[2].Y, p[3].Y), r[1].y2 = max(p[2].Y, p[3].Y);
	solve();
  }
  return 0;
}
