#include<bits/stdc++.h>
using namespace std;
string s;
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin>>s;
    int n = s.size();
    vector<int> z(n);
    z[0] = 0;
    int l = 0, r = 0;
    for(int j = 1; j < n; ++j){
        z[j] = max(0, min(z[j-l], r-j+1));
        while(j + z[j] < n  && s[z[j]] == s[j+z[j]]){
            l = j, r = j+z[j], z[j]++;
        }
    }
    for(int x: z)cout<<x<<' ';
    cout << '\n';
    int i=1, len=0;
    vector<int> lps(n);
    lps[0] = 0;
    while(i < n){
        if (s[i]==s[len]) lps[i++] = ++len;
        else if(len!=0) len = lps[len-1];
        else lps[i++] = 0;
    }
    for(int x: lps)cout<<x<<' ';   
}
