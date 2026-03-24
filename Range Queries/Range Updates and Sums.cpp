#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,q;
vector<int> arr;
struct Node{
  ll val = 0, sum = 0, set = 0;
  bool hasSet = false;
};
vector<Node> st;
void build(int v=1, int tl=0, int tr=n-1){
  if (tl==tr){
	st[v].val = arr[tl];
	return;
  }
  int tm = tl + ((tr-tl)/2);
  build(2*v, tl, tm);
  build(2*v+1, tm+1, tr);
  st[v].val = st[2*v].val + st[2*v+1].val;
}
void apply_set(int v, int len, ll val){
  st[v].hasSet = 1;
  st[v].sum = 0;
  st[v].set = val;
  st[v].val = val * len;
}
void apply_sum(int v, int len, ll val){
  if (st[v].hasSet) st[v].set += val;
  else st[v].sum += val;
  st[v].val += val * len;
}
void push_down(int v, int tl, int tr){
  int tm = tl + ((tr-tl)/2);
  if (st[v].hasSet){
	apply_set(2*v, tm-tl+1, st[v].set);
	apply_set(2*v+1, tr-tm, st[v].set);  
    st[v].hasSet = 0;
  }
  if (st[v].sum != 0){	
	apply_sum(2*v, tm-tl+1, st[v].sum);
	apply_sum(2*v+1, tr-tm, st[v].sum);  
    st[v].sum = 0;
  }
}
void range_update(int ql, int qr, ll val, bool isSet, int v = 1, int tl=0, int tr = n-1){
  if (ql > tr || tl > qr) return;
  if (ql <= tl && tr <= qr){
	if (isSet) apply_set(v, tr-tl+1, val);
	else apply_sum(v, tr-tl+1, val);
	return;
  }
  int tm = tl + ((tr-tl)/2);
  push_down(v, tl, tr);
  range_update(ql, qr, val, isSet, 2*v, tl, tm);
  range_update(ql, qr, val, isSet, 2*v+1, tm+1, tr);
  st[v].val = st[2*v].val + st[2*v+1].val;
}
ll query(int ql, int qr, int v=1, int tl=0, int tr=n-1){
  if (tl>qr || tr < ql) return 0;
  if (ql <= tl && tr <= qr) return st[v].val;
  int tm = tl + ((tr-tl)/2);
  push_down(v,tl,tr);
  return query(ql,qr, 2*v, tl, tm) + query(ql, qr, 2*v+1,tm+1, tr);
}
int main(){
  ios_base::sync_with_stdio(0); cin.tie(0);
  cin>>n>>q;
  arr.resize(n); for(auto &i: arr) cin>>i;
  st.assign(4*n, Node());
  build();
  while(q--){
	int t,a,b; cin>>t>>a>>b; --a,--b;
	if (t < 3){
	  int x; cin>>x;
	  range_update(a,b,x,t-1);
	} else cout << query(a,b) << '\n';
  }									
  return 0;
}
