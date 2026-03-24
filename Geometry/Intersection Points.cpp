#include<bits/stdc++.h>
using namespace std;
const int M = 1e6;
const int N = 2*M + 2;
struct BIT {
  int n;
  vector<int> arr, bit;
  BIT(int n) : n(n), arr(n), bit(n+1){}
  void update(int p, int v){
	arr[p] += v;
	for(++p; p<=n; p += p&-p)
	  bit[p]+=v;
  }
  int query(int p){
	int ans=0;
	for(++p; p>=1; p -= p&-p)
	  ans+=bit[p];
	return ans;
  }
  int query(int l, int r){
	return query(r)- query(l-1);
  }
};
struct E{
  int x1,y1,x2,y2,t;
  E(int a,int b,int c,int d,int e) : x1(a),y1(b),x2(c),y2(d),t(e){}
};
int main(){
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n; cin>>n;
  BIT tree(N);
  long long ans=0;
  vector<E> v;
  while(n--){
	int x1,y1,x2,y2;cin>>x1>>y1>>x2>>y2;
	if (x1 == x2){ // vertical
	  v.emplace_back(x1,y1,x2,y2,2);
	}else{//horizontal y1==y2
	  v.emplace_back(x1,y1,x2,y2,1);//ini
	  v.emplace_back(x2,y2,x2,y2,3);//fin
	}
  }
  sort(v.begin(), v.end(), [&](const E &a, const E &b){
	return a.x1 < b.x1 || (a.x1==b.x1 && a.t<b.t);
  });
  for(auto &[x1,y1,x2,y2,t] : v){
	y1+=M;
	if (t==1){
	  tree.update(y1,1);
	}else if(t==3){
	  tree.update(y1,-1);
	}else{
	  y2+=M;
	  ans+=tree.query(y1,y2);
	}
  }
  cout<<ans<<'\n';
  return 0;
}
