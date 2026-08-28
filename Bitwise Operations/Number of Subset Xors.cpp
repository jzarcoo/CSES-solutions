#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n; cin>>n;
    vector<ll> basis;
    while(n--){
        ll x; cin>>x;
        for(const ll &b : basis){
            x = min(x, b^x);
        }
        if(x) basis.push_back(x);
    }
    ll r = 1LL << (int)basis.size();
    cout << r<<'\n';
}
