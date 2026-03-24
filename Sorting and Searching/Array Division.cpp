#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using vll = vector<ll>;
#define fori(i,a,b) for(int i=a; i<b; i++)
#define all(v) v.begin(),v.end()
ll n,k;
vll a;
ll first_true(ll l, ll r, auto f){
    r++;
    while(l<r){
        ll m = l + (r-l) /2;
        if (f(m)){
            r = m;
        }else{
            l = m+1;
        }
    }
    return l;
}
void solve(){
    ll l = *max_element(all(a));
    ll r = accumulate(all(a), 0LL);
    auto f = [&](ll m){
        ll curr=0;
        ll subarrays=0;
        fori(i,0,n){
            if (a[i] > m) return false;
            if (curr + a[i] > m){
                curr = 0;
                subarrays++;
            }
            curr += a[i];
        }
        if (curr>0){
            subarrays++;
        }
        return subarrays <= k;
    };
    cout << first_true(l, r, f) << '\n';
}
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin>>n>>k;
    a.resize(n);
    for(auto &i:a)cin>>i;
    solve();
    return 0;
}