#include<bits/stdc++.h>
using namespace std;
typedef long long  ll;
#define all(z) z.begin(), z.end()
const ll MAXN = 20;
ll fact[MAXN+1];
void solve(ll n, ll k){
    k--;
    vector<ll> orig(n); iota(orig.begin(), orig.end(), 1);
    for(ll i=0; i<n; i++){
        ll d = k/fact[n-1-i];
        k %= fact[n-1-i];
        cout << orig[d] << ' ';
        orig.erase(orig.begin()+d);
    }
    cout << endl;
}
void solve(ll n, vector<ll> &v){
    ll k = 1;
    vector<ll> orig(n); iota(orig.begin(), orig.end(), 1);
    for(ll i=0; i<n; i++){
        ll pos = lower_bound(all(orig), v[i]) - orig.begin();
        k += pos * fact[n-1-i];
        orig.erase(orig.begin()+pos);
    }
    cout << k << endl;
}
void solve(ll t){
    if(t==1){
        ll n, k; cin>>n>>k;
        solve(n, k);
    }else{
        ll n; cin>>n;
        vector<ll> v(n); for(auto &i: v) cin>>i;
        solve(n, v);
    }
}
void build(){
    fact[0] = 1;
    for(ll i=1; i<=MAXN; i++){
        fact[i] = i * fact[i-1];
    }
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int t; cin>>t;
    build();
    while(t--){
        ll op; cin>>op;
        solve(op);
    }
}
