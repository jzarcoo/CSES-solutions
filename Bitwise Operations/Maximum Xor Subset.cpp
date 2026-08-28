#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=2e5+5;
const ll B = 30;
ll n, a[N];
vector<int> basis;
void solve(){
    for(int i=1; i<=n; i++){
        ll x = a[i];
        for(ll b : basis){
            x = min(x, x^b);
        }
        if(x) basis.push_back(x);
    }
    ll ans = 0;
    for(ll b : basis){
        if((ans ^ b) > ans){
            ans ^=b;
        }
    }
    cout << ans << '\n';
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin>>n;
    for(int i=1; i<=n; i++){
        cin>>a[i];
    }
    solve();
}
