#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 1e9+7;
ll binpow(ll a, ll b, ll m){
    ll r =1;
    a%=m;
    while(b){
        if(b&1) r = (r*a)%m;
        a=(a*a)%m;
        b>>=1;
    }
    return r;
}
ll phi(ll n){
    ll r=n;
    for(ll i=2; i*i<=n; i++){
        if(n%i==0){
            while(n%i==0) n/=i;
            r -= r/i;
        }
    }
    if(n>1){
        r -= r/n;
    }
    return r;
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    ll n, m, ans=0; cin>>n>>m;
    auto add = [&](ll d) -> ll{
        return (phi(n/d)%MOD * binpow(m, d, MOD)) % MOD;
    };
    for (ll d=1; d*d<=n; d++){
        if(n%d==0){
            ans = (ans + add(d)) % MOD;
            if(d != n/d){
                ans = (ans + add(n/d)) % MOD;
            }
        }
    }
    cout << (ans * binpow(n, MOD-2, MOD)) % MOD;
}

