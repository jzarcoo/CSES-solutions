#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const ll MOD=1e9+7;
ll binpow(ll a, ll b, ll mod){
    ll r=1;
    a%=mod;
    while(b){
        if(b&1)r=(r*a)%mod;
        a=(a*a)%mod;
        b>>=1;
    }
    return r;
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    ll n; cin>>n;
    ll num = 1, sum=1, prod=1;

    ll num2 = 1;
    
    for(int i=0;i<n;i++){
        ll p, k;
        cin>>p>>k;
	
        num=(num*(k+1))%MOD;
	
        ll tmp = ((binpow(p, k+1, MOD) - 1) * binpow(p-1, MOD-2, MOD)) % MOD;
        sum=(sum*tmp)%MOD;

        

        prod = binpow(prod, k+1, MOD);
        ll pp = binpow(p, (k*(k+1))/2, MOD);
        pp = binpow(pp, num2, MOD);
        prod = prod * pp % MOD;
        
        num2 = (num2 * (k+1)) % (MOD-1);
        
    }
    cout<<num;
    cout<<' '<<sum;
    cout <<' '<<prod;
    cout << '\n';
    return 0;
}
