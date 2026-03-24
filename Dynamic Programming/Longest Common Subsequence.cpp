#include<bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef vector<vi> vvi;
#define cinv(v) for(auto &i: v) cin>>i;
#define fori(i,a,b) for(int i=a;i<b;i++)
#define print(v) for(auto &i:v)cout<<i<<' ';
void solve(){
  string a, b; cin>>a>>b;
  int n = a.size(), m=b.size();
  // int n,m; cin>>n>>m;
  // vi a(n); cinv(a);
  // vi b(m); cinv(b);
  vvi dp(n+1, vi(m+1,0));
  fori(i,1,n+1){
	fori(j,1,m+1){
	  if (a[i-1]==b[j-1]){
		dp[i][j] = 1 + dp[i-1][j-1];
	  }else{
		dp[i][j] = max(dp[i][j-1], dp[i-1][j]);	
	  }
	}
  }
  fori(i,0,n+1){
	fori(j,0,m+1){
	  cout << dp[i][j]<<' ';
	}
	cout<<'\n';
  }
  int len = dp[n][m];
  cout << len <<endl;
  vector<char> lcs(len);
  int i=n, j=m;
  while(len){
	if (a[i-1]==b[j-1]){
	  lcs[len-1] = a[i-1];
	  i = i-1;
	  j = j-1;
	  len--;
	} else if (dp[i-1][j] > dp[i][j-1]){
	  i--;
	}else{
	  j--;
	}
  }
  print(lcs);
}
int main(){
  ios_base::sync_with_stdio(0);cin.tie(nullptr);cout.tie(nullptr);
  solve();
  return 0;
}
