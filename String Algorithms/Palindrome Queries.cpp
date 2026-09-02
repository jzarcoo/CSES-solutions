/*
 * STRING HASHING 
 * polynomial hashing / polynomial rolling hash function
 * check if two strings are equal comparing their hash values
 *
 * calculate the hash value of any substring in O(1) after O(n) time processing
 *
 */
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

// MAXLEN
const int N = 2e5+5;
const int C = 2;

// hash
// prime modulus
const int B = 1e9 + 9;
// power
const int A = 9973;
ll p[N+1], my_hash[C][N+1], ft[C][N+1];

int n, q;
string s;
string rev;

void update(int pos_hash, int pos, ll val){
    auto &f = ft[pos_hash];
    for(++pos; pos <= N; pos += pos & -pos){
        f[pos] += val;
        f[pos] %= B;
    }
}

ll sum(int pos_has, int pos){
    auto &f = ft[pos_has];
    ll s = 0;
    for(++pos; pos; pos -= pos & - pos){
        s += f[pos];
        s%= B;
    }
    return s;
}

void build_hash(string s, int pos=0, int mod = B){
    auto &h = my_hash[pos];
    h[0] = 0;
    for(int i=0; i<s.length(); i++){
        // h[i+1] = ((h[i]*A % mod) + s[i]) % mod;
        h[i+1] = s[i] * p[i] % mod;
        update(pos, i, h[i+1]);
    }
}

ll get_hash(int l, int r, int pos=0, int mod = B){
    auto &h = my_hash[pos];
    // raw_val = (h[r+1] - (h[l] * p[r-l+1]));
    ll raw_val = sum(pos, r) - sum(pos, l-1);
    return (raw_val % mod + mod) % mod;
}

ll sub(ll a, ll b, ll mod = B){
    return ((a-b)%mod+mod) % mod;
}

void update_hash(int k, char c){
    --k;
    ll val = c * p[k] % B;
    ll old = s[k] * p[k] % B;
    ll delta = sub(val, old);
    update(0, k, delta);

    val = c * p[n-1-k] % B;
    old = rev[n-1-k] * p[n-1-k] % B;
    delta = sub(val, old);
    update(1, n-1-k, delta);
    s[k] = c;
    rev[n-1-k] = c;
}

void preprocess(){
    p[0] = 1LL;
    for(int i=1; i<=N; i++){
        p[i] = p[i-1] * A % B;
    }
    build_hash(s);
    rev = s;
    reverse(rev.begin(), rev.end());
    build_hash(rev, 1);
}

bool query(int l, int r){
    --l,--r; // 0-indexed
    ll h =  get_hash(l, r, 0);
    ll rev_h =  get_hash(n-1 - r, n-1 - l, 1);
    
    h = h * p[n-1-r] % B;
    rev_h = rev_h * p[l] % B;
    
    return h == rev_h;
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin>>n>>q;
    cin>>s;
    preprocess();
    while(q--){
        int t; cin>>t;
        if(t==1){
            int k; char c; cin>>k>>c;
            update_hash(k, c);
        }else{
            int l, r; cin>>l>>r;
            cout << (query(l, r) ? "YES\n" : "NO\n");
        }
    }
}
