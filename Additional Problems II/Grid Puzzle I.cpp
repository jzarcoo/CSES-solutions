#include<bits/stdc++.h>
using namespace std;
struct Edge{
    int from, to, cap, flow = 0;
};
struct Dinic{
    int n, s, t, m = 0;
    vector<vector<int>> g;
    vector<int> level, ptr;
    vector<Edge> edges;
    queue<int> q;
    Dinic(int n, int s, int t) :
        n(n),
        s(s),
        t(t)
        {
            level.resize(n);
            ptr.resize(n);
            g.resize(n);
        }
    void add_edge(int a, int b, int cap){
        edges.push_back(Edge{a,b,cap});
        g[a].push_back(m++);
        edges.push_back(Edge{b,a,0});
        g[b].push_back(m++);
    }
    bool hayCamino(){
        fill(level.begin(), level.end(), -1);
        level[s]=0;
        q.push(s);
        while(!q.empty()){
            int v =q.front(); q.pop();
            for(int e_id : g[v]){
                Edge &e = edges[e_id];
                if(level[e.to]==-1 && e.cap>e.flow){
                    level[e.to] = 1 + level[e.from];
                    q.push(e.to);
                }
            }
        }
        return level[t] != -1;
    }
    int dfs(int v, int f){
        if(v==t || f==0) return f;
        for(int &i=ptr[v]; i<g[v].size(); i++){
            int e_id = g[v][i];
            Edge &e = edges[e_id];
            if(level[e.to] == 1 + level[e.from]){
                if(int f2 = dfs(e.to, min(f, e.cap-e.flow))){
                    e.flow += f2;
                    edges[e_id^1].flow -=f2;
                    return f2;
                }
            }
        }
        return 0;
    }
    int maxflow(){
        int tot = 0;
        while(hayCamino()){
            fill(ptr.begin(), ptr.end(), 0);
            if (int pushed = dfs(s, 1e9)){
                tot += pushed;
            }
        }
        return tot;
    }
};
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n; cin>>n;
    vector<int> rows(n); for(auto &r:rows) cin>>r;
    vector<int> cols(n); for(auto &c:cols) cin>>c;
    int tot_rows = accumulate(rows.begin(), rows.end(), 0);
    int tot_cols = accumulate(cols.begin(), cols.end(), 0);
    if(tot_rows != tot_cols){
        cout << -1 <<'\n';
        return 0;
    }
    int s = 0, t = 2*n+1;
    Dinic d(t+1, s, t);
    for(int v=1; v<=n; v++){
        d.add_edge(0, v, rows[v-1]);
        d.add_edge(v+n, t, cols[v-1]);
        for(int w=1; w<=n; w++){
            d.add_edge(v, w+n, 1);
        }
    }
    int maxflow = d.maxflow();
    //cout << maxflow<<endl;
    if(maxflow != tot_rows){
        cout << -1<<'\n';
        return 0;
    }
    vector<string> grid(n, string(n, '.'));
    //
    for(int r=1; r<=n; r++){
        for(int i=0; i<d.g[r].size(); i++){
            int e_id = d.g[r][i];
            if(e_id &1) continue;
            Edge &e = d.edges[e_id];
            if(e.flow){
                grid[r-1][e.to-1-n] = 'X';
            }
        }
    }
    //
    for(const string & s: grid){
        cout << s<<endl;
    }
}
