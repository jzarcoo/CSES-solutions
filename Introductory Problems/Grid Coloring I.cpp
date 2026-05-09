#include<bits/stdc++.h>
using namespace std;
vector<string> v({"AB", "CD"});
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int h, w; cin>>h>>w;
    for(int r=0; r<h; r++){
        string s; cin>>s;
        for(int c=0; c<w; c++){
            string x = v[(r+c)%2];
            cout << (s[c] == x[0] ? x[1] : x[0]);
        }
        cout <<'\n';
    }
}
