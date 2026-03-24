#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
#define re(v) for(auto &i:v) cin>>i;
#define fori(i,a,b) for(int i=a;i<b;i++)
int N;
vi arr, bit;
void update(int i, int delta){
  for(; i<=N; i+= i & -i){
	bit[i]+=delta;
  }
}
int preffix_search(int p){
  int ans = 0;
  for(int i=1<<__lg(N); i; i/=2){
	if (ans+i<=N && bit[ans+i] < p){
	  p -= bit[ans+i];
	  ans += i;
	}
  }
  return ans+1; 
}
int main(){
  ios_base::sync_with_stdio(false); cin.tie(nullptr);
  cin>>N;
  arr.resize(N); re(arr);
  bit.assign(N+1,0);
  fori(i,1,N+1) update(i, 1);
  fori(i,0,N){
	int q; cin>>q;
	int ans = preffix_search(q);
   	cout << arr[ans-1]<<' ';
	update(ans,-1);
  }
  return 0;
}
