#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
void fuckin_number(__int128 x){
    if(x==0){
        cout<<0;
        return;
    }
    if(x<0){
        cout<<'-';
        x = -x;
    }
    string r;
    while(x > 0){
        r += (x % 10) + '0';
        x /= 10;
    }
    reverse(r.begin(), r.end());
    cout<<r;
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n; cin>>n;
    vector<ll> xs(n), ys(n);
    for(int i=0; i<n; i++){
        cin >> xs[i] >> ys[i];
    }
    sort(xs.begin(), xs.end());
    sort(ys.begin(), ys.end());
    __int128 r = 0;
    for(int i = 0; i < n; i++) {
        r += ((i<<1) - n + 1) * (xs[i] + ys[i]);
    }
    fuckin_number(r);
}
