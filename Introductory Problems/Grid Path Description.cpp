#include<bits/stdc++.h>
using namespace std;
const int X[]={1,0,-1,0};
const int Y[]={0,1,0,-1};
bool g[9][9];
string s;
int n, ans=0;
void search(int p, int r, int c){
    bool ub = g[r-1][c],
        db = g[r+1][c],
        lb = g[r][c-1],
        rb = g[r][c+1];
    if ((r==7 && c==1 && p<48)
        || (ub && db && !lb && !rb)
        || (lb && rb && !ub && !db)) {
        return;
    }
    if(p==n){
        ans += (r==7 && c == 1);
        return;
    }
    g[r][c] = 1;
    if (s[p] != '?'){
        int i=2;
        if(s[p]=='R') i=1;
        if(s[p]=='L') i=3;
        if(s[p]=='D') i=0;
        if (!g[r+X[i]][c+Y[i]])
            search(p+1, r+X[i], c + Y[i]);
    }else{
        for(int i=0; i<4; i++){
            if (!g[r+X[i]][c+Y[i]])
                search(p+1, r+X[i], c+Y[i]);
        }
    }
    g[r][c] = 0;
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin>>s; n = s.size();
    for(int i=0; i<9; i++){
        g[0][i] = g[i][0] = g[8][i] = g[i][8] = 1;
    }
    search(0,1,1);
    cout<<ans<<'\n';
}
