#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll raiz = 1e6;
vector<ll> primes;
char mark[raiz+1];
void sieve(){
    for(ll i=2; i<=raiz; ++i){
        if(!mark[i]){
            primes.emplace_back(i);
            for(ll j=i*i; j<=raiz; j+=i){
                mark[j]=true;
            }
        }
    }
}
ll segmented_sieve(ll l, ll r){
    vector<char> isPrime(r-l+1, true);
    for(ll i : primes){
        for(ll j=max(i*i, (l+i-1)/i*i); j<=r; j+=i){
            isPrime[j-l]=false;
        }
    }
    if(l==1)
        isPrime[0]=false;
    for(int i=0; i<r-l+1; i++){
        if(isPrime[i]){
            return l+i;
        }
    }
    return -1;
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    sieve();
    int t; cin>>t;
    while(t--){
        ll n; cin>>n;
        cout << segmented_sieve(n+1, n+raiz+1)<<'\n';
    }
    
}
