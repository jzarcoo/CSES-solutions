#include<bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n, k; cin>>n>>k;
    vector<int> m(k);
    vector<bool> v(n+1, 0);
    for(int i=0; i<k; i++){
        cin>>m[i];
        v[m[i]]=1;
    }
    string ans = "";
    for(int i=1; i<=n; i++){
        bool losp = 0;
        for(int x : m){
            if (i-x>=0 && v[i-x]==0){
                losp = 1;
                break;
            }
        }
        if(losp) {
            ans += "W";
            v[i]=1;
        }else ans += "L";
        
    }
    cout << ans << '\n';
}
