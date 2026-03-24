#include<bits/stdc++.h>
using namespace std;
typedef struct node* pnode;
struct node{
  char c;
  int prior, cnt=1;
  pnode l=0, r=0;
  bool rev;
  node(char c) : c(c), prior(rand()) {}
} *t;
int cnt(pnode t){
  return t ? t->cnt : 0;
}
void upd(pnode t){
  if (!t) return ;
  t->cnt = 1 + cnt(t->l) + cnt(t->r);
}
void push(pnode t){
  if (!t) return;
  if (t->rev){
	t->rev=0;
	swap(t->l, t->r);
	if(t->l) t->l->rev ^= 1;
	if(t->r) t->r->rev ^= 1;
  }
}
void split(pnode t, int k, pnode &l, pnode &r){
  if (!t)
	return void (l=r=0);
  push(t);
  if (k <= cnt(t->l))
	split(t->l, k, l, t->l), r=t;
  else
	split(t->r, k-1-cnt(t->l), t->r, r), l=t;
  upd(t);
}
void merge(pnode &t, pnode l, pnode r){
  push(l);
  push(r);
  if(!l || !r)
	t = l?l:r;
  else if (l->prior > r->prior)
	merge(l->r, l->r, r), t=l;
  else
	merge(r->l, l, r->l), t=r;
  upd(t);
}
void print(pnode t){
  if (!t) return;
  push(t);
  print(t->l);
  cout<<t->c;
  print(t->r);
}
int main(){
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n, m, f; cin>>n>>m;
  char c;
  while(n--){
	cin>>c;
	merge(t, t, new node(c));
  }
  pnode t1,t2,t3;
  while(m--){
	cin>>n>>f;
	split(t, n-1, t1, t2);
	split(t2, f-n+1, t2, t3);
	t2->rev=1;
	merge(t,t1,t2);
	merge(t,t,t3);
  }
  print(t);
  return 0;
}
