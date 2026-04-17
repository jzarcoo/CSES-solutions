#include<bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n; cin>>n;
    vector<string> g(n); for(auto &i: g) cin>>i;
    string res;
    res += g[0][0];
    vector<pair<int,int>> frontera;
    frontera.emplace_back(0,0);
    for(int i=1; i<n+n-1; i++){
        char next = 'Z';
        for(auto &[r, c] : frontera){
            if(r+1 < n)
                next = min(next, g[r+1][c]);
            if(c+1 < n)
                next = min(next, g[r][c+1]);            
        }
        res += next;
        vector<pair<int,int>> siguiente;        
        for(auto &[r, c] : frontera) {
            if (r+1 < n && g[r+1][c] == next){
                siguiente.emplace_back(r+1, c);
            }
            if (c+1 < n && g[r][c+1] == next){
                siguiente.emplace_back(r, c+1);
            }
        }
        sort(siguiente.begin(), siguiente.end());
        siguiente.erase(unique(siguiente.begin(), siguiente.end()), siguiente.end());
        frontera = siguiente;
    }
    cout << res << '\n';
}
