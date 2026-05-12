#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 505,
    MOD = 1e9+7;

ll fact[N+1], inv[N+1];
string s;
int n;
ll dp[N][N];

ll binpow(ll a, ll b, ll m){
    ll r=1;
    a%=m;
    while(b){
        if(b&1)
            r = r*a % m;
        a=a*a%m, b>>=1;
    }
    return r;
}
void build(){
    fact[0] = 1;
    for(ll i=1; i<=N; i++){
        fact[i] = i * fact[i-1] % MOD;
    }
    inv[N] = binpow(fact[N], MOD-2, MOD);
    for(ll i=N; i>=1; i--){
        inv[i-1] = i * inv[i] % MOD;
    }
}
ll comb(ll n, ll k){
    if(k<0||k>n) return 0LL;
    return fact[n] * inv[k] % MOD * inv[n-k] % MOD;
}

void solve(){
    for(int i=1; i<N; i++) dp[i][i-1] = 1;
    
    for(int len=2; len<=n; len+=2){
        for(int i=1; i+len-1<=n; i++){
            int j = i+len-1;
            
            for(int k=i+1; k<=j; k+=2){
                
                if(s[i-1] == s[k-1]){
                    ll term = dp[i+1][k-1] * dp[k+1][j] % MOD;                    
                    term = term * comb(len/2, (k-i+1)/2) % MOD;
                    
                    dp[i][j] = (dp[i][j] + term) % MOD;
                }
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    build();
    cin>>s;
    n = s.size();

    solve();

    cout << dp[1][n] << '\n';
}
