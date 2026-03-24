#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll>  vll;
#define cinv(v) for(auto &i:v) cin>>i
ll n;
vll arr;
ll diff(ll i, ll s1,ll s2){
    if (i==n){
        return abs(s1-s2);
    }
    return min(diff(i+1, s1 + arr[i], s2), diff(i+1, s1, s2 + arr[i]));
}
void solve(){
    cout << diff(0,0,0)<<'\n';
}
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin>>n;
    arr.resize(n);
    cinv(arr);
    solve();
    return 0;
}