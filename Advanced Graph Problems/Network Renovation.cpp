#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define sz(z) (int)z.size()
const int N=1e5+1;
int n;
vector<int> g[N];
vector<int> hojas;
void dfs(int v, int p){
    int ch = 0;
    if(v==1 && sz(g[v]) == 1){
        hojas.pb(v);
    }
    for(int c : g[v]){
        if(c!=p){
            ch++;
            dfs(c, v);
        }
    }
    if(ch==0){
        hojas.pb(v);
    }
}
void solve(){
    dfs(1, 1);

    int cm = (1+sz(hojas)) / 2;
    int m  = sz(hojas) / 2;

    cout << cm << '\n';
    for(int i=0; i<cm; i++){
        cout << hojas[i] << ' ' << hojas[i+m] << '\n';
    }

    
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin>>n;
    for(int i=1; i<n; i++){
        int a, b; cin>>a>>b;
        g[a].pb(b);
        g[b].pb(a);
    }
    solve();
}
