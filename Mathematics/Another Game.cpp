#include<bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        bool ok = 0;
        for(int i=0, x; i<n; i++){
            cin>>x;
            ok |= x&1;
        }
        cout << vector<string>({"second", "first"})[ok] << '\n';
    }
}
