#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n;
bool sum2squares(ll x){
    for(ll d=3; d*d <=x; d+=2){
        if(x%d==0){
            int cnt = 0;
            while(x%d==0){
                cnt++;
                x/=d;
            }
            if(d%4==3
               && cnt%2==1){
                return 0;
            }
        }
    }
    if(x>1
       && x%4==3) {
        return 0;
    }
    return 1;
}
int solve(){
    ll tmp = 8*n + 1;
    ll x = round(sqrt(tmp));
    if(x*x == tmp) {
        return 1;
    }
    if(sum2squares(8*n+2)) {
        return 2;
    }
    return 3;    
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int t; cin>>t;
    while(t--){
        cin>>n;
        cout << solve() <<'\n';
    }
}
