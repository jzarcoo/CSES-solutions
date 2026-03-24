#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b)for(int i=a; i<b;i++)
struct point{
  long long x,y; //ox, oy
  int id;
};
struct cmp_x{
  bool operator()(const point &a, const point &b){
	return a.x < b.x || (a.x == b.x && a.y < b.y);
  }
};
struct cmp_y{
  bool operator()(const point &a, const point &b){
	return a.y < b.y;
  }
};
int n;
vector<point> a, t;
long double mindist = LLONG_MAX; // 1e20
long long ans;
pair<point,point> best_pair;
void upd_ans(const point &a, const point &b){
  long long mul = (a.x-b.x)*(a.x-b.x) + (a.y-b.y)*(a.y-b.y);
  long double d = sqrt(mul);
  if(d<mindist){
	mindist=d;
	ans = mul;
	best_pair = {a,b};
  }
}
void rec(int l, int r){
  if(r-l<=3){
	rep(i,l,r){
	  rep(j,i+1,r){
		upd_ans(a[i],a[j]);
	  }
	}
	sort(begin(a)+l, begin(a)+r, cmp_y());
	return;
  }
  int m = l + (r-l)/2;
  long long  midx = a[m].x;
  rec(l,m);
  rec(m,r);
  merge(begin(a)+l, begin(a)+m, begin(a)+m, begin(a)+r, begin(t), cmp_y());
  copy(begin(t), begin(t) + r-l, begin(a) + l);
  int tsz=0;
  rep(i,l,r){
	if(abs(a[i].x-midx)<mindist){
	  for(int j=tsz-1; j>=0 && a[i].y-t[j].y < mindist; --j){
		upd_ans(a[i],t[j]);
	  }
	  t[tsz++]=a[i];
	}
  }
}
int main(){
  ios_base::sync_with_stdio(0);cin.tie(0);
  cin>>n;
  a.resize(n); t.resize(n);
  rep(i,0,n){
    cin>>a[i].x>>a[i].y;
	a[i].id=i;
  }
  sort(begin(a), end(a), cmp_x());
  rec(0,n);
  cout<<ans<<endl;
  return 0;
}


