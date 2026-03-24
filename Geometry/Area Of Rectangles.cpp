#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
#define pb push_back
#define endl '\n'
#define sz(v)(int)v.size()
#define all(v) v.begin(), v.end()
#define fori(i,a,b) for(int i=a; i<b;i++)
const int MX_X = 1e6;
const int MX_N = 2*MX_X + 1 + 1;
const int INF = INT_MAX;
const int NEUTER = INF;
struct Event{
  int t, x, y1, y2;
};
struct Node{
  int mn;
  ll rep;
};
int n;
Node st[MX_N*4];
ll lazy[MX_N*4];
vector<Event> ev;
Node comb(Node &a, Node &b){
  if(a.mn < b.mn) return a;
  if (a.mn>b.mn) return b;
  return Node{a.mn, a.rep+b.rep};
}
void build(int v=1, int tl=0, int tr=MX_N-1){
  if (tl==tr){
	st[v] = Node{0,1};
	return;
  }
  int tm = tl + ((tr-tl)/2);
  build(2*v, tl, tm);
  build(2*v+1, tm+1, tr);
  st[v] = comb(st[2*v], st[2*v+1]);
}
void apply(int v, int len, int val){
  st[v].mn += val;
  lazy[v] += val;
}
void push_down(int v, int tl, int tr){
  if (lazy[v] == 0) return;
  int tm = tl + ((tr-tl)/2);
  apply(2*v, tm-tl+1, lazy[v]);
  apply(2*v+1, tr-tm, lazy[v]);  
  lazy[v] = 0;
}
void range_update(int ql, int qr, int val, int v = 1, int tl=0, int tr = MX_N-1){
  if (ql > tr || tl > qr){
	return;
  }
  if(ql <= tl && tr <= qr){
	apply(v, tr-tl+1, val);
	return;
  }
  int tm = tl + ((tr-tl)/2);
  push_down(v, tl, tr);
  range_update(ql, qr, val, 2*v, tl, tm);
  range_update(ql, qr, val, 2*v+1, tm+1, tr);
  st[v] = comb(st[2*v], st[2*v+1]);
}
ll query(){
  return MX_N - st[1].rep;
}
int main(){
  ios_base::sync_with_stdio(0); cin.tie(0);
  cin>>n;
  fori(i,0,n){
	int x1,y1,x2,y2; cin>>x1>>y1>>x2>>y2;
	x1+=MX_X, x2+=MX_X, y1+=MX_X, y2+=MX_X;
	ev.pb(Event{1, x1, y1, y2-1});
	ev.pb(Event{-1, x2, y1, y2-1});
  }
  sort(all(ev), [&](Event &a, Event &b){
	return a.x < b.x;
  });
  build();
  ll ans = 0;
  range_update(ev[0].y1, ev[0].y2, ev[0].t);
  fori(i,1,2*n){
	ans += query() * (ev[i].x - ev[i-1].x);
	range_update(ev[i].y1, ev[i].y2, ev[i].t);
  }
  cout << ans << endl;
  return 0;
}
