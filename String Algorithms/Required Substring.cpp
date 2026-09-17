#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1e9+7;
const int K = 26;
int n; 
string s;
vector<int> pi_function(const string &s){
    int i = 1, prev = 0;
    int n = (int) s.size();
    vector<int> lpps(n, 0);
    while(i < n){
        if (s[i] == s[prev]) lpps[i++] = ++prev;
        else if (prev) prev = lpps[prev - 1];
        else i++;
    }
    return lpps;
}
vector<vector<int>> build_aut(string s){
    s += '#';
    int n = (int)s.size();
    vector<int> pi = pi_function(s);
    vector<vector<int>> aut(n, vector<int>(K));
    for(int i=0; i<n; i++){
        for(int c=0; c<K; c++){
            if(i> 0 && s[i] != 'A' + c)
                aut[i][c] = aut[pi[i-1]][c];
            else 
                aut[i][c] = i + (s[i] == 'A' + c);
        }
    }
    return aut;
}
void solve(){
    vector<vector<int>> aut = build_aut(s);
    int m = (int)s.size();
    vector<vector<ll>> dp(n+1, vector<ll>(m+1));
    dp[0][0] = 1;
    ll tot = 1;
    for(int len = 1; len <= n; len++) {
        tot = tot * K % MOD;
        for (int pi = 0; pi < m; pi++) {
            if (dp[len-1][pi] == 0) continue;
            for (int c = 0; c < K; c++) {
                int new_pi = aut[pi][c];
                if (new_pi == m) continue;
                dp[len][new_pi] = (dp[len][new_pi] + dp[len-1][pi]) % MOD;
            }
        }
    }
    ll sum = 0;
    for(int pi = 0; pi < m; pi++){
        sum = (sum + dp[n][pi]) % MOD;
    }
    ll ans = ((tot - sum) % MOD + MOD) % MOD;
    cout << ans << '\n';
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin>>n>>s;
    solve();
}
