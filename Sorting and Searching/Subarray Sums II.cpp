#include<bits/stdc++.h>
using namespace std;
using ll=long long;
int main(){
    ios_base::sync_with_stdio(false);cin.tie(nullptr);
    ll n, target; cin>>n>>target;
    map<ll,ll> mp({{0,1}});
    ll prefix=0, ans=0;
    while(n--){
        ll x; cin>>x;
        prefix += x;
        ans += mp[prefix - target];
        ++mp[prefix];
    }
    cout<<ans<<'\n';
    return 0;
}