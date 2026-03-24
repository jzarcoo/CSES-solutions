#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    ll n;cin>>n;
    ll k; cin>>k;
    ld ans=0;
    for(int i=1; i<=k; i++){
        ld p = pow((ld)(i - 1) / k, n);
        ans += 1.0 - p;
    }   
    cout<< fixed << setprecision(6) << ans;
}
