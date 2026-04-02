#include<bits/stdc++.h>
using namespace std;
const int INF = 1e9;
int n; 
// dist[node] = the position of node in the alternating path
vector<int> match, dist;
vector<vector<int>> g;
vector<bool> visited;
bool bfs(){
    queue<int> q;
    // The alternating path starts with unmatched nodes
    for (int node = 1; node <= n; node++){
        if (!match[node]){
            q.push(node);
            dist[node] = 0;
        } else {
            dist[node] = INF;
        }
    }
    dist[0] = INF;
    while (!q.empty()){
        int node = q.front(); q.pop();
        if (dist[node] >= dist[0]) continue; // ¿ u != 0 ?
        for (int son : g[node]) {
            // If the match of son is matched
            if (dist[match[son]] == INF) {
                dist[match[son]] = 1 + dist[node];
                q.push(match[son]);
            }
        }
    }
    // Returns true if an alternating path has been found
    return dist[0] != INF;
}
bool dfs(int node){
    if (node==0) return true;
    for (int son : g[node]){
        if(dist[match[son]] == dist[node] + 1 && dfs(match[son])){
            match[node]=son;
            match[son]=node;
            return true;
        }
    }
    dist[node] = INF;
    return false;
}
int hopcroft_karp(){
    int cnt = 0;
    while (bfs()) {
        for (int node = 1; node <= n; node++) {
            if (!match[node] && dfs(node)) {
                cnt++;
            }
        }
    }
    return cnt;
}
void find_visited(int node){
    visited[node] = 1;
    for (int v : g[node]){
        if (v != match[node] && !visited[v]) {
            visited[v] = 1;
            if(match[v] && !visited[match[v]]){
                find_visited(match[v]);
            }
        }
    }
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin>>n;
    int rows = n, cols = n;
    int N = rows + cols + 1;
    dist.resize(N); match.resize(N); g.resize(N);
    for(int r=1; r<=n; r++){
        for(int c=1; c<=n; c++){
            char x; cin>>x;
            if(x=='o'){
                g[r].push_back(c+n);
                // g[c+n].push_back(r);
            }
        }
    }
    cout << hopcroft_karp() << '\n';
    // Minimum Vertex Cover
    visited.assign(N, false);
    for(int node=1; node<=n; node++){
        if (!match[node]){
            find_visited(node);
        }
    }
    for(int i=1; i<=n; i++){
        if(!visited[i]) cout<<"1 "<<i<<'\n';
        if(visited[i+n]) cout<<"2 "<<i<<'\n';
    }        
}
