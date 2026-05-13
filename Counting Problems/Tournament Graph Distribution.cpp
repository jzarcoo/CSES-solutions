#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pairs(n) ((n)*((n)-1)) / 2

const ll MOD = 1e9+7;
const ll N=500;

ll n;

ll fact[N+1], inv[N+1];
ll T[N+1], C[N+1], dp[N+1][N+1];

ll binpow(ll a, ll b, ll m){
    ll r =1;
    a%=m;
    while(b){
        if(b&1){
            r = r * a % m;
        }
        a = a * a % m, b >>= 1;
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
    if(k<0||k>n) return 0;
    return fact[n]*inv[k]% MOD * inv[n-k]%MOD;
}

void labeled_graphs(){
    for(ll i=1; i<=n; i++){
        T[i] = binpow(2, pairs(i), MOD);
    }    
}

ll sub(ll a, ll b, ll m){
    return (a - b + m) % m;
}


void connected_labeled_graphs(){
    for(ll V=1; V<=n; V++){
        C[V] = T[V];
        for(ll j=1; j<V; j++){
            ll connected = comb(V, j) * C[j] % MOD;
            ll disconnected = connected * T[V-j] % MOD;
            C[V] = sub(C[V], disconnected, MOD);
        }
    }
}

void labeled_graphs_with_k_connected_componentes(){
    
    for(ll V=1; V<=n; V++){
        dp[V][1] = C[V];
    }

    for(ll c=2; c<=n; c++){
        for(ll v=c; v<=n; v++){
            for(ll s=1; s<=v-c+1; s++){
                ll connected = comb(v, s) * C[s] % MOD;
                ll term = connected * dp[v-s][c-1] % MOD;
                dp[v][c] = (dp[v][c] + term) % MOD;
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin>>n;

    build();
    
    labeled_graphs();
    connected_labeled_graphs();

    labeled_graphs_with_k_connected_componentes();

    for(int k=1; k<=n; k++){
        cout << dp[n][k] <<'\n';
    }
}
