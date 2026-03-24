#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vll = vector<ll>;
#define fori(i,a,b) for(int i=a;i<b;i++)
ll N, Q;
vll bit, arr;
void update(int i, ll val){
    arr[i] += val;
    ++i;
    while(i <= N){
        bit[i] += val;
        i += i & -i;
    }
}
ll query(int i){
    ll ans = 0;
    ++i;
    while(i > 0){
        ans += bit[i];
        i -= i & -i;
    }
    return ans;
}
int main(){
  ios_base::sync_with_stdio(0); cin.tie(0);
  cin>>N>>Q;
  arr.resize(N);
  bit.resize(N+1); // 1-based
  fori(i,0,N){
    ll n; cin>>n;
    update(i, n - arr[i]);
  }
  while(Q--){
    ll op; cin >> op;
    if (op == 1){
        ll pos, val; cin >> pos >> val; --pos;
        update(pos, val - arr[pos]);
    }else{
      int a, b; cin >> a >> b; --a,--b;
      cout << query(b) - query(a-1) << endl;
    }
  }
  return 0;
}
