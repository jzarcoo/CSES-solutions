#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef complex<ll> P;
#define X real()
#define Y imag()
#define rep(i,a,b) for(int i=a;i<b;++i)
#define sz(a) (int)a.size()
#define all(a) a.begin(), a.end()
int n, m;
vector<P> poly;
P p;
ll cross(P a, P b){
  return (conj(a)*b).Y;
}
ll dot(P a, P b){
  return a.X*b.X+a.Y*b.Y;
}
bool on_segment(P p, P a, P b){
  return cross(b-a,p-a)==0 &&
	min(a.X,b.X)<=p.X&& p.X<=max(b.X,a.X) &&
	min(a.Y,b.Y)<=p.Y&&p.Y<=max(b.Y,a.Y);
}
ll cross(P p, P a, P b){
  return cross(a-p,b-p);
}
void solve(){
  int c=0;
  bool f=0;
  rep(i,0,n){
	int j = (i+1)%n;
	if (on_segment(p, poly[i], poly[j])){
	  f=1;
	  break;
	}
	if (poly[i].Y <= p.Y && p.Y < poly[j].Y &&
		cross(p, poly[i], poly[j])>0)
	  ++c;
	if (poly[j].Y <= p.Y && p.Y < poly[i].Y &&
		cross(p, poly[j], poly[i])>0)
	  ++c;
  }
  if (f) cout<<"BOUNDARY\n";
  else if(c&1) cout<<"INSIDE\n";
  else cout<<"OUTSIDE\n";
}
int main(){
  ios_base::sync_with_stdio(0);cin.tie(0);
  cin>>n>>m;
  rep(i,0,n){
	int x,y; cin>>x>>y;
	poly.emplace_back(x,y);
  }
  while(m--){
	int x,y; cin>>x>>y;
	p={x,y};
	solve();
  }
  return 0;
}
