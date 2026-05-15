#include<bits/stdc++.h>
using namespace std;
const int N = 2e3;
int dp[N+1];
int main(){
    ios::sync_with_stdio(0); cin.tie(0);

    dp[1] = dp[2] = 0;
    for(int i=3; i<=N; i++){
        
        set<int> grundies;
        for(int d=1; 2*d<i; d++){
            int g = dp[d] ^ dp[i-d];
            grundies.insert(g);
        }
        
        int r = 0;
        while(grundies.count(r)){
            r++;
        }
        
        dp[i] = r;
    }

    
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        cout << ((n>=N || dp[n]) ? "first" : "second") << '\n';
    }
}
