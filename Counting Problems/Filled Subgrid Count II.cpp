#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n, l; cin>>n>>l;
    vector<string> g(n);
    for(int i=0; i<n; i++){
        cin>>g[i];
    }   
        
    vector<ll> h(n), ans(l);
    for(int r=0; r<n; r++){
        vector<ll> dp(n);             
        for(int c=0; c<n; c++){
            if(r && g[r-1][c] == g[r][c]){
                h[c]++;
            }else{
                h[c] = 1;
            }
        }
        int s = 0;
        while(s<n){
            stack<int> st;
            int e = s;
            while(e+1<n && g[r][s] == g[r][e+1]) e++;
            for(int i=s; i<=e; i++){
                while(!st.empty() && h[st.top()] >= h[i]){
                    st.pop();
                }
                if(st.empty()){
                    dp[i] = 1LL * h[i] * (i-s+1);
                }else{
                    int prev = st.top();
                    dp[i] = dp[prev] + 1LL * (i-prev) * h[i];
                }   
                st.push(i);
                ans[g[r][s] - 'A'] += dp[i];
            }
            s = e+1;
        }
 
    }
 
    for(auto &x:ans) cout << x<<'\n';
}
