#include<bits/stdc++.h>
using namespace std;
using ll=long long;
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    ll n; cin>>n;
    ll ans=n*(n+1)/2;
    ll s=0;
    for(int i=0;i<n-1;i++){
        ll x; cin>>x;
        s+=x; 
    }
    cout<<ans-s<<'\n';
    return 0;
}