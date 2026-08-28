#include<bits/stdc++.h>
using namespace std;
const int N=1e7;
typedef long long ll;
ll a[N+1], b[N+1];
void solve(ll n){
    
    for(ll i=0; i*i<=n; i++){
        for(ll j=i; i*i+j*j<=n; j++){
            ll r = n - i*i -j*j;
            if(a[r]!=-1){
                cout << i<<' ';
                cout << j<<' ';
                cout << a[r]<<' ';
                cout << b[r]<<'\n';
                return;
            }
        }
    }
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    fill(a, a+N+1, -1);
    for(ll i=0; i*i <=N; i++){
        for(ll j=i; i*i +j*j <=N; j++){
            ll s = i*i +j*j;
            if(a[s]==-1){
                a[s]=i;
                b[s]=j;
            }
        }
    }
    int t; cin>>t;
    while(t--){
        ll n; cin>>n;
        solve(n);
    }
}
