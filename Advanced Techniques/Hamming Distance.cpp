#include<bits/stdc++.h>
using namespace std;
#pragma GCC target("popcnt")
const int N=2e4;
const int K=30;
bitset<30> grid[N];
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n, k; cin>>n>>k;
    for(int i=0; i<n; i++){
        string s; cin>>s;
        for(int j=0; j<k; j++)
            if(s[j]=='1')
                grid[i].set(j);
    }
    int ans = k;
    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){
            int c = (grid[i] ^ grid[j]).count();
            if(ans>c) ans=c;
        }
    }
    cout<<ans;
}
