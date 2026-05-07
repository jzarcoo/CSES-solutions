#include<bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    string s; cin>>s;
    int n = s.length();

    //manacher
    string t;
    for(char c: s){
        t += string("#")+c;
        
    }
    t+="#";

    int nt = t.size();
    t = "$" + t + "^";
    
    vector<int> p(nt +2);
    int l=0, r=1;
    for(int i=1; i<=nt; i++){
        if(i<=r){
            p[i] = min(r-i, p[l + r-i]);
        }
        while(t[i-p[i]] == t[i+p[i]]){
            p[i]++;
        }
        if(i+p[i] > r){
            l = i - p[i];
            r = i + p[i];
        }
    }

    int center = 0, len = 0;
    for(int i=1; i<=nt; i++){
        if(p[i] > len){
            len = p[i];
            center = i;
        }
    }

    len--;
    int ini = (center-1-len)/2;
    cout << s.substr(ini, len)<<endl;
}
