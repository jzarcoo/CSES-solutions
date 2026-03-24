#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
#define re(v) for(auto &i:v) cin>>i;
#define pb push_back
#define fori(i,a,b) for(int i=a;i<b;i++)
int N;
vi arr, ans;
struct node {
  int c;
  node *l, *r;
  node(int tl,int tr){
	if (tl==tr){
	  c=1;
	}else{
	  int tm = tl + (tr-tl)/2;
	  l = new node(tl, tm);
	  r = new node(tm+1, tr);
	  c = l->c + r->c;
	}
  }
  void erase(int i, int tl, int tr){
	if (c < i) return;
	c--;
	if (tl==tr){
	  ans.pb(arr[tl]);
	}else if(l->c > i){
	  l->erase(i, tl, tl + (tr-tl)/2);
	}else{
	  r->erase(i-l->c, 1 + tl + (tr-tl)/2, tr);
	}
  }
};
int main(){
  ios_base::sync_with_stdio(false); cin.tie(nullptr);
  cin>>N;
  arr.assign(N,0);
  re(arr);
  node *tree = new node(0, N-1);
  fori(i,0,N){
	int q;cin>>q;--q;
	tree->erase(q,0,N-1);
  }
  for(auto &i:ans)cout<<i<<' ';
  return 0;
}
