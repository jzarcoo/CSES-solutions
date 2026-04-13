#include<bits/stdc++.h>
using namespace std;
const int m = 1e9+7;
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    string s;cin>>s;
    vector<int> dp(26);
    int prev = 1;
    for(char c : s){
        int cur = (2LL * prev) % m;
        cur = ((cur - dp[c-'a']) + m) % m;
        dp[c - 'a'] = prev;
        prev = cur;
    }
    int ans = ((prev-1)+m) % m;
    cout << ans;
}
