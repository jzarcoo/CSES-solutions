#include<bits/stdc++.h>
using namespace std;
#pragma GCC target("popcnt")
const int N=3e3;
bitset<N> grid[N];
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n; cin>>n;
    for(int i=0; i<n; i++){
        string s; cin>>s;
        for(int j=0; j<n; j++)
            if(s[j]=='1')
                grid[i].set(j);
    }
    long long ans = 0;
    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){
            long long c = (grid[i] & grid[j]).count();
            ans += c * (c-1) / 2;
        }
    }
    cout<<ans;
}
