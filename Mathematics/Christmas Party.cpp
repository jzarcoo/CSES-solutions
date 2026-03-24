#include<bits/stdc++.h>
using namespace std;
const int mod = 1e9+7;
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    int n; cin>>n;
    vector<long long> de(n+1);
    de[1]=0;
    de[2]=de[0]=1;
    for(int i=3; i<=n; i++){
        de[i] = ((i-1) * (de[i-1]+de[i-2]) % mod) % mod;
    }
    cout<<de[n];
}
