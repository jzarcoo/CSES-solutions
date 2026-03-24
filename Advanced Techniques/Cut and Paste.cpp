#include<bits/stdc++.h>
using namespace std;
typedef struct node* pnode;
struct node{
  char key;
  int prior, cnt=1;
  pnode l=0, r=0;
  node(char key) : key(key), prior(rand()) {}
} *t;
int cnt(pnode t){
  return t ? t->cnt : 0;
}
void upd(pnode t){
  if (!t) return;
  t->cnt = 1 + cnt(t->l) + cnt(t->r);
}
void split(pnode t, int key, pnode &l, pnode &r){
  if (!t)l=r=0;
  else if (cnt(t->l) >= key)
	split(t->l, key, l, t->l), r=t;
  else
	split(t->r, key - 1 - cnt(t->l), t->r, r), l= t;
  upd(t);
}
void merge(pnode &t, pnode l, pnode r){
  if (!l || !r)
	t= l ? l : r;
  else if (l->prior > r->prior)
	merge(l->r, l->r, r), t=l;
  else
	merge(r->l, l, r->l), t=r;
  upd(t);
}
void print(pnode p){
  if(p->l)
	print(p->l);
  cout << p->key;
  if (p->r)
	print(p->r);
}
int main(){
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n, m, z;cin>>n>>m;
  char c;
  while(n--){
    cin>>c;
	merge(t, t, new node(c));
  }
  pnode t1,t2,t3;
  while(m--){
	cin>>n>>z;
	split(t, n-1,t1,t2);
	split(t2, z-n+1,t2,t3);
	merge(t,t1,t3);
	merge(t,t,t2);
  }
  print(t);
  return 0;
}
