#include<bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    string s; cin>>s;
    int ns = s.size();
    
    string t;
    for(char c: s){
        t += string("#") +  c;      
    }
    t+="#";
    int nt = t.size();

    vector<int> p(nt+2);
    t = "$" + t + "^";
    int l=0, r=1;
    for(int i=1; i<=nt; i++){
        if(i<=r){
            p[i] = min(r-i, p[l+r-i]);
        }
        while(t[i-p[i]-1] == t[i+p[i]+1]){
            p[i]++;
        }
        if(i+p[i]>r){
            l = i-p[i];
            r = i+p[i];
        }
    }

    vector<int> maxx(ns, 1);
    
    for(int i=1; i<=nt; i++){
        if(p[i]==0) continue;
        int pos = (i-1-p[i])/2 + p[i]-1;
        maxx[pos] = max(maxx[pos], p[i]);
    }
    
    for(int i=ns-2; i>=0; i--){
        maxx[i] = max(maxx[i], maxx[i+1] - 2);
    }
    
    for(int x : maxx) cout << x <<' ';
    
}
