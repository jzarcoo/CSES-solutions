#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1e9+7;
const int MAXN = 1e6;
ll fact[MAXN+1], inv[MAXN+1];
ll n;
string s;
ll binpow(ll a, ll b, ll m){
    ll r=1;
    a%=m;
    while(b){
        if(b&1)r=r*a%m;
        a = a*a%m, b>>=1;
    }
    return r;
}
ll comb(ll n, ll k){
    if(k<0||n<k) return 0LL;
    return fact[n] * inv[k] % MOD * inv[n-k]  % MOD;
}
int solve(){
    if(n&1){
        return 0;
    }
    int b = 0;
    for(char c: s){
        if(c=='('){
            b++;
        }else{
            b--;
        }
        if(b<0){
            return 0;
        }
    }
    int k = s.length();
    int f = n-k;
    if(f < b
       || (f-b)%2==1){
        return 0;
    }
    int x = (f-b) >> 1;
    ll ans = comb(f, x) - comb(f, x-1) + MOD;
    if(ans>=MOD) ans-=MOD;
    return ans;
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin>>n;
    cin>>s;
    fact[0]=1;
    for(int i=1; i<=MAXN; i++)
        fact[i] = i * fact[i-1] % MOD;
    inv[MAXN] = binpow(fact[MAXN], MOD-2, MOD);
    for(int i=MAXN; i>=1; i--)
        inv[i-1] = i*inv[i] % MOD;

    cout << solve()<<'\n';
}
