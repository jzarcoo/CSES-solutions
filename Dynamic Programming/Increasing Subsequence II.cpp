#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD=1e9+7;
#define all(v) v.begin(), v.end()
struct BIT{
    int n;
    vector<ll> bit;
    BIT(int n) : n(n), bit(n+1){}
    void add(int i, int d){
        for(++i; i<=n; i+=i &-i) bit[i]= (bit[i]+d) % MOD;
    }
    ll sum(int i){
        ll s=0;
        for(++i; i; i-= i&-i) s= (s+bit[i])%MOD;
        return s;
    }
};
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n; cin>>n;
    vector<int> v(n), in; for(auto &i: v)cin>>i;
    in = v;
    sort(all(v));
    v.erase(unique(all(v)), v.end());
    auto id = [&](int x) -> int{
        return lower_bound(all(v), x) - v.begin();
    };
    int len = v.size();
    BIT b(len);
    ll ans = 0;
    for(int i=0; i<n; i++){
        int x = id(in[i]);
        ll c = (1 + b.sum(x-1)) % MOD;
        ans = (ans + c) % MOD;
        b.add(x, c);
    }
    cout<<ans;
}
