#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using pll = pair<ll,ll>;
#define fi first
#define se second
ll n, k, x, a, b, c, ans;
stack<pll> s1,s2;
ll mini(){
    return (s1.empty() || s2.empty()) ? (s1.empty() ? s2.top().se : s1.top().se) : min(s1.top().se, s2.top().se);
}
void add(ll e){
    ll mn = s1.empty() ? e : min(e, s1.top().se);
    s1.push({e, mn});
}
void remove(){
    if (s2.empty()){
        while (!s1.empty()){
            ll e = s1.top().fi; s1.pop();
            ll mn = s2.empty() ? e : min(e, s2.top().se);
            s2.push({e, mn});
        }   
    }
    // ll rem = s2.top().fi; 
    s2.pop();
}
int main(){
    ios_base::sync_with_stdio(false);cin.tie(nullptr);
    cin>>n>>k>>x>>a>>b>>c;
    ll i=0;
    do {
        add(x);
        x = (a * x + b) % c;
    } while(++i < k);
    
    ans = mini();

    while(i++ < n){
        remove();
        add(x);
        ans ^= mini();
        x = (a * x + b) % c;
    }
    cout<<ans<<'\n';
    return 0;
}