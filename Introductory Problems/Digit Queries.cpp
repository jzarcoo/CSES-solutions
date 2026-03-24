#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ll;
int q;
ll k;
void solve(){
    int d=1;
    ll nums=9;
    ll ini=1;
    while(k>d*nums){
        k-= d*nums;
        d++;
        nums*=10;
        ini*=10;
    }
    ini += --k /d;
    cout << to_string(ini)[k%d] << '\n';
}
int main(){
    ios_base::sync_with_stdio(0);; cin.tie(0);
    cin>>q;
    while(q--){
        cin>>k;
        solve();
    }
    return 0;
}
