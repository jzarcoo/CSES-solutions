#include<bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
#define pb push_back
#define endl '\n'
#define sz(v)(int)v.size()
#define all(v) v.begin(), v.end()
#define p(v) for(int i: v) cout<<i<<' ';
bool comp(int i, int j){
  cout << "? "<<i<<' '<<j<<endl;
  cout.flush();
  string s; cin>>s;
  return s=="YES";
}
vi merge_sort(vi &v){
  if (sz(v)<=1) return v;
  int m = sz(v)/2;
  vi l(v.begin(),v.begin()+m);
  vi r(v.begin()+m, v.end());
  l = merge_sort(l), r = merge_sort(r);
  int i=0,j=0;
  vi ans;
  while(i < sz(l) && j < sz(r)){
	if (comp(l[i], r[j])){
	  ans.pb(l[i++]);
	}else{
	  ans.pb(r[j++]);
	}
  }
  while(i<sz(l)) ans.pb(l[i++]);
  while(j<sz(r)) ans.pb(r[j++]);
  return ans;
}
int main(){
  ios_base::sync_with_stdio(0); cin.tie(0);
  int n; cin>>n;
  vi v(n); iota(all(v), 1);
  v = merge_sort(v);
  vi ans(n+1);
  for(int i=0; i<=n;i++){
	ans[v[i]]=i+1;
  }
  cout<< "! ";
  for(int i=1;i<=n;i++) cout<<ans[i]<<' ';
  return 0;
}
