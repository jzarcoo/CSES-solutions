#include <bits/stdc++.h>
using namespace std;
const int N=3e3, K=26;
bool vis[N][N];
vector<int> apariciones[K][N];
int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n, k; cin>>n>>k;
    for(int i=0; i<n; i++){
        string s; cin>>s;
        for(int j=0; j<n; j++){
            apariciones[s[j]-'A'][i].emplace_back(j);
        }         
    }
    for(int l=0; l<k; l++){
        for(int r=0; r<n; r++){
            if (apariciones[l][r].size()<2) continue;
            for(int i=0; i<apariciones[l][r].size(); i++){
                for(int j=i+1; j<apariciones[l][r].size(); j++){
                    if (vis[apariciones[l][r][i]][apariciones[l][r][j]]){
                        cout<<"YES\n";
                        goto fin;       
                    }
                    vis[apariciones[l][r][i]][apariciones[l][r][j]] = 1;
                }
            }
        }
        cout<<"NO\n";
    fin:
        if(l+1<k) memset(vis, 0, sizeof vis);
    }
    return 0;
}
