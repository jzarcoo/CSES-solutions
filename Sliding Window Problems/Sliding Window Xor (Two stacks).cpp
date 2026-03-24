#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pll=pair<ll,ll>;
#define fi first
#define se second
stack<pll> s1,s2;
ll op(const ll &a, const ll &b){
    return a^b;
}
void add(ll e){
    ll x = s1.empty() ? e : op(s1.top().se, e);
    s1.push({e,x});
}
ll query(){
    return s1.empty() || s2.empty() ? s1.empty() ? s2.top().se : s1.top().se : op(s2.top().se, s1.top().se);
}
ll remove(){
    if (s2.empty()){
        while(!s1.empty()){
            ll elem = s1.top().fi; s1.pop();
            ll x = s2.empty() ? elem : op(elem , s2.top().se);
            s2.push({elem, x});
        }
    }
    ll rem = s2.top().fi; s2.pop();
    return rem;
}
int main(){
    ios_base::sync_with_stdio(false);cin.tie(nullptr);
    ll n, k; cin>>n>>k;
    ll x,a,b,c; cin>>x>>a>>b>>c;
    ll i=0;
    do{
        add(x);
        x = (a*x+b)%c;
    } while(++i < k);
    ll ans = query();
    while(i++<n){
        ll r = remove();
        add(x);
        ans = op(ans, query());
        x = (a*x+b)%c;
    }
    cout<<ans<<'\n';
    return 0;
}