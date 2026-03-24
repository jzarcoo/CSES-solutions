#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vll;
#define pb push_back
#define all(v) v.begin(), v.end()
#define fori(i,a,b) for(int i=a; i<b;i++)
#define sz(v) (int) v.size()
struct BIT{
  int n;
  vll arr, bit;
  BIT(int n) : n(n), arr(n), bit(n+1) {}
  void add(int i, ll delta){
	arr[i] += delta;
	for(++i;i<=n; i += i & -i)
	  bit[i]+=delta;
  }
  ll query(int i){
	ll s = 0;
	for(++i; i>0; i -= i& -i)
	  s+=bit[i];
	return s;
  }
  ll query(int l, int r) {
	if (r < l) return 0LL;
	return query(r) - (l ? query(l-1) : 0LL);
  }
};
int main(){
  ios_base::sync_with_stdio(0); cin.tie(0);
  int n, q; cin>>n>>q;
  vector<int> empleados(n); for(auto &i: empleados) cin>>i;
  vector<array<int, 3>> queries;
  vector<int> salarios(empleados);
  while(q--){
	char c; int a, b; cin>>c>>a>>b;
	queries.pb({c=='?',a,b});
    salarios.pb(b);
	salarios.pb(a);
  }
  sort(all(salarios));
  salarios.erase(unique(all(salarios)), salarios.end());
  auto id = [&](int v) -> int {
	return lower_bound(all(salarios), v) - salarios.begin();
  };
  BIT bit(sz(salarios));
  for(int x : empleados){
	bit.add(id(x), 1);
  }
  for(auto [t,a,b] : queries){
	if (t){
	  cout << bit.query(id(a),id(b)) <<'\n';
	}else{
	  bit.add(id(empleados[a-1]), -1);
	  empleados[a-1] = b;
	  bit.add(id(b), 1);
	}
  }
  return 0;
}
