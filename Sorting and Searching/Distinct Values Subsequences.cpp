#include<bits/stdc++.h>
using namespace std;
const int mod = 1e9+7;
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n; cin>>n;
    vector<int> v(n);
    for(int &i:v)cin>>i;
    map<int, int> freq;
    for(int x:v){
        freq[x]++;
    }
    long long ans = 1;
    for(auto [k, v]:freq){
        ans *= 1LL * (v+1);
        ans %= mod;
    }
    cout << ans-1 << '\n';
}
