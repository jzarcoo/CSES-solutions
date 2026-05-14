#include<bits/stdc++.h>
#pragma GCC target("popcnt")
using namespace std;
#define pb push_back
const int N = 5e4+1;
int n, m, q;
int nscc = 0;
int timer = 0;
int low[N], tin[N], root[N];
vector<int> g[N], topo, st, cond[N];
bitset<N> reach[N];
void dfs(int v){
    tin[v] = low[v] = ++timer;
    st.pb(v);
    for(int to: g[v]){
        if(tin[to]==0){
            dfs(to);
            low[v] = min(low[v], low[to]);
        }else if(root[to] == 0){
            low[v] = min(low[v], tin[to]);
        }
    }
    if(tin[v]==low[v]){
        ++nscc;
        topo.pb(nscc);
        while(1){
            int w = st.back(); st.pop_back();
            root[w] = nscc;
            if(w==v) break;
        }
    }
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin>>n>>m>>q;
    for(int i=0; i<m; i++){
        int a, b; cin>>a>>b;
        g[a].pb(b);
    }
    // scc
    for(int v=1; v<=n; v++){
        if(tin[v]==0){
            dfs(v);
        }
    }
    // cond
    for(int v=1; v<=n; v++){
        for(int to:g[v]){
            if(root[v] != root[to]){
                cond[root[v]].pb(root[to]);
            }
        }
    }
    for(int i=0; i<nscc; i++){
        int v = topo[i];
        reach[v].set(v);
        for(int to : cond[v]){
            reach[v] |= reach[to];
        }
    }
    while(q--){
        int a, b; cin>>a>>b;
        if(reach[root[a]].test(root[b])){
            cout << "YES\n";
        }else {
            cout << "NO\n";
        }
    }
}
