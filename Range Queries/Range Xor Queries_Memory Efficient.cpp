#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
struct seg{
  vector<ll> st;
  int n;
  seg(vector<int> v) : n((int) v.size()) {
	st.resize(2*n);
	build(v,0,0,n-1);
  }
  void build(vector<int> &a, int v, int tl, int tr){
	if(tl==tr){
	  st[v]=a[tl];
	  return;
	}
	int tm = tl + (tr-tl)/2, l=v+1, r = v+2*(tm-tl+1);
	build(a, l, tl, tm);
	build(a, r, tm+1, tr);
	st[v] = st[l] ^ st[r];
  }
  ll query(int v, int tl, int tr, int ql, int qr){
	if (ql <= tl && tr <= qr){
	  return st[v];
	}
	if (ql > tr || qr < tl){
	  return 0;
	}
	int tm = tl + (tr-tl)/2, l=v+1, r = v+2*(tm-tl+1);
    return query(l,tl,tm,ql,qr) ^ query(r,tm+1,tr,ql,qr);
  }
};
int main(){
  ios_base::sync_with_stdio(0); cin.tie(0);
  int n, q; cin>>n>>q;
  vector<int> v(n); for(auto &i:v) cin>>i;
  seg t(v);
  while(q--){
	int a,b; cin>>a>>b;
	cout << t.query(0,0,n-1,a-1,b-1) <<endl;
  }
  return 0;
}
