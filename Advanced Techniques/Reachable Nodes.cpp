#include<bits/stdc++.h>
#pragma GCC target("popcnt")
using namespace std;
const int N = 5e4+1;
bitset<N+1> reachable[N];
vector<int> g[N];
int n, m, d[N];
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin>>n>>m;
    for(int i=0; i<m; i++){
        int a,b; cin>>a>>b; // a->b 
        g[b].push_back(a); // a <- b
        ++d[a];
    }
    queue<int> q;
    for(int i=1; i<=n; i++){
        if(d[i]==0){
            q.push(i);
        }
    }
    while(!q.empty()){
        int u = q.front(); q.pop();
        reachable[u].set(u);
        for(int to : g[u]){
            reachable[to] |= reachable[u];
            if(--d[to]==0){
                q.push(to);
            }
        }
    }
    for(int v=1; v<=n; v++){
        cout << reachable[v].count() << ' ';
    }
}
