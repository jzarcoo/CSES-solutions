#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll>  vll;
#define cinv(v) for(auto &i:v) cin>>i
#define fori(i,a,b) for(ll i=a;i<b;i++)
ll n;
vll arr;
void solve(){
    ll ans=LLONG_MAX;
    fori(mask,0,(1<<n)){
        ll s1=0,s2=0;
        fori(i,0,n){
            if (mask & (1<<i)) {
                s1+= arr[i];
            }else{
                s2 += arr[i];
            }
        }
        ans = min(ans,abs(s1-s2));
    }
    cout<<ans<<'\n';
}
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin>>n;
    arr.resize(n);
    cinv(arr);
    solve();
    return 0;
}