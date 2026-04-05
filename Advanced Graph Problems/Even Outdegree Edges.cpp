#include<bits/stdc++.h>
using namespace std;
const int N=1e5;
vector<int> g[N+1];
int odd[N+1], tin[N+1];
int timer = 0;
int n, m;
vector<pair<int,int>> ans;
void dfs(int v, int p){
    tin[v] = timer++;
    for(int c : g[v]){
        if(c==p) continue;
        if(tin[c] == -1){
            dfs(c, v);
            if(odd[c]){
                ans.emplace_back(c, v);
                odd[c] = 0;
            }else{
                ans.emplace_back(v, c);
                odd[v] ^= 1;
            }
        }else if (tin[c] < tin[v]){
            ans.emplace_back(v, c);
            odd[v]^=1;
        }
    }
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin>>n>>m;
    while(m--){
        int a, b;
        cin>>a>>b;
        g[a].emplace_back(b);
        g[b].emplace_back(a);
    }
    fill(tin+1, tin+n+1, -1);
    for(int v=1; v<=n; v++)
        if(tin[v]==-1)
            dfs(v, 0);
    if(accumulate(odd+1, odd+1+n, 0)){
        cout<<"IMPOSSIBLE";
        return 0;
    }
    for(auto &[a, b]: ans){
        cout<<a<<' '<<b<<'\n';
    }
}
