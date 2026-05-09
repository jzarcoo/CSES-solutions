#include<bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    string s; cin>>s;
    int n = s.length();
    vector<int> freq(26, 0);
    for(char c: s){
        freq[c-'A']++;
    }
    string ans;
    for(int i=0; i<n; i++){
        for(char ch= 'A'; ch<='Z'; ch++){
            int &f = freq[ch-'A'];
            if(f==0 || (!ans.empty() && ans.back() ==ch)) continue;
            int mx = *max_element(freq.begin(), freq.end());
            bool ok=1;
            if(mx != f){
                ok = (mx + (mx-1)) <= n-i-1;
            }else{
                ok = (mx + (mx-1)) <= n-i;
            }
            if(ok){
                ans+=ch;
                --f;
                break;
            }
        }
    }
    if(ans.empty()) ans = "-1";
    cout << ans <<'\n';
}
