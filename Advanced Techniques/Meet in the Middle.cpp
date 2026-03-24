#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using vll=vector<ll>;
#define fori(i,a,b) for(int i=a;i<b;i++)
#define all(a) a.begin(), a.end()
ll n, t, ans;
vll a, X, Y;
void subarray_sums(ll l, vll &v, ll c){
    v.resize(1<<l);
    fori(i,0,1<<l){
        ll s =0;
        fori(j,0,l)
            if (i & (1<<j)) s = (s + a[j+c]) ;
        v[i] = s;
    }
}
ll solve(){
    subarray_sums(n/2, X, 0);
    subarray_sums(n-n/2, Y, n/2);
    sort(all(Y));
    for(ll x : X) {
        auto it = equal_range(all(Y), t - x);
        ans += it.second - it.first;
    }
    return ans;
}
int main(){
    ios_base::sync_with_stdio(false);cin.tie(nullptr);
    ans=0;
    cin>>n>>t; a.resize(n); for(auto &i: a)cin>>i;
    cout<<solve()<<'\n';
    return 0;
}
