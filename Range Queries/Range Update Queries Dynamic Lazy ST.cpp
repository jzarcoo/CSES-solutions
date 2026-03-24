#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back
#define rz resize
#define re(v) for(auto &i:v) cin>>i;
#define fori(i,a,b) for(int i=a;i<b;i++)
const int NEUTER=0;
struct node{
  ll val = 0, lazy = 0;
  node *l, *r;
};
void apply(node *v, int len, ll delta){
  v->val += len * delta;
  v->lazy += delta;
}
void push_down(node *v, int tl, int tr){
  if (!v->l) v->l = new node();
  if (!v->r) v->r = new node();
  int tm = tl + (tr-tl)/2;
  apply(v->l, tm-tl+1, v->lazy);
  apply(v->r, tr-tm, v->lazy);
  v->lazy=0;
}
void range_update(node *v, int tl, int tr, int ql, int qr, ll delta){
  if (!v || tl > qr || tr < ql) return;
  if (ql <= tl && tr <= qr){
	apply(v, tr-tl+1, delta);
	return;
  }
  push_down(v, tl, tr);
  if (!v->l) v->l = new node();
  if (!v->r) v->r = new node();
  int tm = tl + (tr-tl)/2;
  range_update(v->l, tl, tm, ql, qr, delta);
  range_update(v->r, tm+1, tr, ql, qr, delta);
  v->val = ((v->l) ? v->l->val : 0) + ((v->r) ? v->r->val : 0);
}
ll query(node *v, int tl, int tr, int ql, int qr){
  if (!v || tl > qr || tr < ql) return NEUTER;
  if (ql <= tl && tr <= qr)	return v->val;
  push_down(v, tl, tr);
  int tm = tl + (tr-tl)/2;
  return query(v->l, tl, tm, ql, qr) + query(v->r, tm+1, tr, ql, qr);
}
int N, Q;
node *tree = new node();
int main(){
  ios_base::sync_with_stdio(false); cin.tie(nullptr);
  cin>>N>>Q;
  fori(i,1,N+1){
	ll v; cin>>v;
	range_update(tree, 1, N, i, i, v);
  }
  fori(i,0,Q){
	int q;cin>>q;
	if (q == 2){
	  int k; cin>>k;
	  cout<<query(tree, 1, N, k, k)<<'\n';
	}else{
	  int l, r, v; cin>>l>>r>>v;
	  range_update(tree, 1, N, l, r, v);
	}
  }
  return 0;
}
