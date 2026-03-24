#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    ll n; cin>>n;
    cout<<n<<' ';
    while(n!=1){
        n = (n&1) ? n*3+1 : n>>1;
        cout<<n<<' ';
    }
    cout<<'\n';
    return 0;
}