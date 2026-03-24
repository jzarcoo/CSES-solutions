#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vll;
typedef vector<vll> vvll;

#define sz(a) (int)a.size()
#define FOR(i,a,b) for(int i=a; i<b;i++)
#define FORE(i,a,b) for(int i=a; i<=b;i++)

const ll MOD = 1e9+7;
const int INF = 2;

ll binpow(ll a, ll b){
  ll r = 1;
  a %= MOD;
  while(b){
	if(b & 1) r = (r * a) % MOD;
	a = (a * a) % MOD;
	b >>= 1;
  }
  return r;
}

ll inv(ll a){
  return binpow(a, MOD-2);
}

// const double EPS = 1e-9;
int gauss(vvll a, vll &ans){ // a = m | b
  int n = sz(a), m = sz(a[0]) - 1;
  vector<int> where(m, -1);
  for(int col = 0, row=0; col < m && row < n; col++){
	int sel = -1; // row
	for(int i = row; i < n; i++){
	  // abs (a[i][col]) > abs (a[sel][col])
	  if(a[i][col] !=0){
		sel = i;
		break; //
	  }
	}
	// abs (a[sel][col]) < EPS
	if(sel ==-1)
	  continue;
	for (int i=col; i<=m; ++i)
	   swap (a[sel][i], a[row][i]);
	where[col] = row;
	ll inv_pivot = inv(a[row][col]);
	for(int j = col; j <= m; j++) //
	  a[row][j] = (a[row][j] * inv_pivot) % MOD; //
	for(int i = 0; i < n; i++) 
	  if(i != row && a[i][col] != 0){ // i != row
		// double c = a[i][col] / a[row][col];
		ll factor = a[i][col]; 
		for(int j = col; j <= m; j++){
		  // a[i][j] -= a[row][j] * c;
		  a[i][j] = (a[i][j] - factor * a[row][j] % MOD + MOD) % MOD;
		}
	  }
	row++;
  }
  ans.assign(m, 0);
  for(int i = 0; i < m; i++){
	if(where[i] != -1){
	  // ans[i] = a[where[i]][m] / a[where[i]][i];
	  ans[i] = a[where[i]][m];
	}
  }
  for(int i = 0; i < n; i++){
	ll sum = 0; // double
	for(int j = 0; j < m; j++){
	  // sum += ans[j] * a[i][j];
	  sum = (sum + ans[j] * a[i][j]) % MOD;
	}
	if(sum != a[i][m]) {// abs (sum - a[i][m]) > EPS
	  return 0;
	}
  }
  for(int i = 0; i < m; i++){
	if(where[i] == -1){
	  return INF;
	}
  }
  return 1; 
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int N, M;
  cin >> N >> M;

  vvll a(N, vll(M+1));
  vll ans;

  for(int i = 0; i < N; i++){
	for(int j = 0; j <= M; j++){
	  cin >> a[i][j];
	  a[i][j] %= MOD;
	}
  }

  if(gauss(a, ans) == 0){
	cout << -1 << "\n";
  } else {
	for(ll x : ans) cout << x << " ";
  }

  return 0;
}
