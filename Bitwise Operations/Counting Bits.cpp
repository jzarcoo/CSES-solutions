#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
#pragma GCC target("popcnt")
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    ull n; cin>>n;
    ull ans=0;
    while(n){
        ull lgf = bit_width(n) - 1;
        if (lgf)
            ans += lgf<<(lgf-1);
        n-= 1ULL<<lgf;
        ans += n+1;
    }
    cout<<ans;
}
