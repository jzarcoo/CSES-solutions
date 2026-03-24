#include<bits/stdc++.h>
using namespace std;
typedef string str;
typedef vector<int> vi;
#define sz(a) (int)a.size()
#define all(a) a.begin(), a.end()
#define FOR(i,a,b) for(int i=a; i<b; i++)
#define each(t, s) for(auto t:s)
 
struct SA{
  str s;
  int n;
  vi sa, isa, lcp;
  SA(str s) : s(s), n(sz(s)+1) {
	gensa(); genlcp();
  }
  void gensa(){
	sa=isa=vi(n); sa[0]=n-1; iota(1+all(sa), 0);
	sort(1+all(sa), [&](int a, int b){ return s[a]<s[b]; });
	FOR(i,1,n){ int a = sa[i-1], b=sa[i];
	  isa[b]=i>1&&s[a]==s[b] ? isa[a]:i;
	}
	for(int len=1; len<n; len*=2){
	  vi csa(sa), is(isa), pos(n); iota(all(pos),0);
	  each(t, csa){ int k=t-len;
		if(k>=0) sa[pos[isa[k]]++] = k; }
	  FOR(i,1,n){ int a=sa[i-1],b=sa[i];
		isa[b]=is[a]==is[b] && is[a+len]==is[b+len] ? isa[a] : i;}
	}
  }
 
  void genlcp(){
	lcp = vi(n-1); int h=0;
	FOR(b,0,n-1){ int a=sa[isa[b]-1];
	  while(a+h < sz(s)&&s[a+h]==s[b+h])++h;
	  lcp[isa[b]-1]=h; if(h)h--; }
  }
};
int main(){
  ios_base::sync_with_stdio(0); cin.tie(0);
  //freopen("input.txt", "r", stdin);
  str s; cin>>s;
  int n = sz(s);
  SA sa = SA(s);
  int mx = 0, idx=-1;
  FOR(i,0,n){
	if(mx < sa.lcp[i]){
	  mx = sa.lcp[i];
	  idx = sa.sa[i];
	}
  }
  cout<<(mx ? s.substr(idx, mx)  : "-1")<<endl;
  return 0;
}

