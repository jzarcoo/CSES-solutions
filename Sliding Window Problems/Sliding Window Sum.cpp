#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define fi first
#define se second
ll n, k, x, a, b, c;
stack<ll> s1,s2;
void add(ll e){
    s1.push(e);
}
ll remove(){
    if (s2.empty()){
        while (!s1.empty()){
            ll e = s1.top(); s1.pop();
            s2.push(e);
        }   
    }
    ll rem = s2.top(); s2.pop();
    return rem;
}
ll solve(){
    ll i = 0, sum = 0;
    do {
        add(x);
        sum += x;
        x = (a * x + b) % c;
    }while(++i<k);
    ll ans = sum;
    while(i++<n){
        sum-=remove();
        add(x);
        sum += x;
        ans ^= sum;
        x = (a * x + b) % c;
    }
    return ans;
}
int main(){
    ios_base::sync_with_stdio(false);cin.tie(nullptr);
    cin>>n>>k>>x>>a>>b>>c;
    cout<<solve()<<'\n';
    return 0;
}