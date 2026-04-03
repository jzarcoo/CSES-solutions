#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ll;
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    ll n;
    int k;
    cin>>n>>k;
    vector<ll> a(k);for(ll &i:a)cin>>i;
    ll ans = 0;
    for(int mask = 1; mask < (1LL<<k); mask++){
        ll mul = 1;
        int cnt = 0;
        bool ok = 1;
        for(int b=0; b<k; b++){
            if(mask & (1<<b)){
                cnt++;
                if (mul > n / a[b]) {
                    ok = 0; break;
                }
                mul *= a[b];
            }
        }
        if (!ok) continue;
        ll sum = n / mul;
        if (cnt & 1){
            ans += sum;
        }else{
            ans-=sum;
        }
    }
    cout<<ans;
}
