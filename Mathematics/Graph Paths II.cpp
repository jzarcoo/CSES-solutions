#include<iostream>
#include<vector>
#include<climits>
using namespace std;
typedef long long ll;
typedef vector<ll> vll;
typedef vector<vll> vvll;
#define fori(i,a,b) for(int i=a; i<b;i++)
#define sz(a) (int)a.size()
const ll MOD=1e9+7;
const ll INF = LLONG_MAX;
void matmul(vvll &a, const vvll&b){
  int n=sz(a), m=sz(a[0]), p=sz(b[0]);
  vvll c(n, vll(p,INF));
  fori(i,0,n) {
	fori(j,0,p){
	  fori(k,0,m){
		if (a[i][k] < INF && b[k][j] < INF)
		  c[i][j] = min(c[i][j], (a[i][k]+b[k][j]));
	  }
	}	
  }
  a=c;
}
vvll makeiden(int n){
  vvll r(n,vll(n,INF));
  fori(i,0,n) r[i][i]=0;
  return r;
}
vvll binpow(vvll a, ll b){
  vvll res=makeiden(sz(a));
  while(b){
	if (b&1) matmul(res,a);
	matmul(a,a);
	b>>=1;
  }
  return res;
}
int main(){
  ios_base::sync_with_stdio(false);cin.tie(nullptr);
  ll n,m,k; cin>>n>>m>>k;
  vvll mat(n, vll(n, INF));
  fori(i,0,m){
	ll a, b, c; cin>>a>>b>>c; --a,--b;
	mat[a][b]=min(mat[a][b], c);
  }
  ll ans = binpow(mat, k)[0][n-1];
  cout<<((ans == INF) ? -1:  ans)<<'\n';
  
  return 0;
}

