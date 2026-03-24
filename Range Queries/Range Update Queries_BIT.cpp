#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vll = vector<ll>;
#define fori(i,a,b) for(int i=a;i<b;i++)
ll N, Q;
vll bit, arr;
void update(int i, ll val){
    for (++i; i <= N; i += i & -i){
        bit[i] += val;
    }
}
ll query(int i){
    ll ans = 0;
    for (++i; i > 0; i -= i & -i){
        ans += bit[i];
    }
    return ans;
}
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin>>N>>Q;
    arr.resize(N); for (auto &i: arr) cin >> i;
    bit.resize(N+2);
    while(Q--){
        ll op; cin >> op;
        if (op == 1){
            ll a, b, c; cin >> a >> b >> c; --a,--b;
            update(a, c); 
            update(b+1, -c);
        }else{
            int pos; cin >> pos; --pos;
            cout << arr[pos] + query(pos) << endl;
        }
    }
    return 0;
}
