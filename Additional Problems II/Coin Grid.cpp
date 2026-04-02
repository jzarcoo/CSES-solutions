#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
struct Edge{
    int from, to;
    ll cap, flow=0;
    Edge(int from, int to, ll cap) : from(from), to(to), cap(cap) {}
};
struct Dinic{
    const ll FLOW_INF = 1e18;
    vector<Edge> edges;
    vector<vector<int>> g;
    int n, m=0,s,t;
    vector<int> level, ptr;
    queue<int> q;
    Dinic(int n, int s, int t) :n(n),s(s),t(t),
                                g(n), level(n), ptr(n) {}
    void add_edge(int from, int to, ll cap){
        edges.emplace_back(from, to, cap);
        edges.emplace_back(to, from, 0);
        g[from].emplace_back(m++);
        g[to].emplace_back(m++);
    }
    bool bfs(){
        fill(level.begin(), level.end(), -1);
        level[s]=0; q.push(s);
        while(!q.empty()){
            int at = q.front(); q.pop();
            for(int id :g[at]){
                Edge &e = edges[id];
                if(e.cap>e.flow && -1 == level[e.to]){
                    level[e.to] = level[at]+1;
                    q.push(e.to);
                }
            }
        }
        return level[t] != -1;
    }
    ll dfs(int v, ll pushed){
        if(v==t||pushed==0) return pushed;
        for(int &i=ptr[v]; i<(int)g[v].size(); i++){
            int id = g[v][i];
            Edge &e = edges[id];
            if(level[v]+1==level[e.to]){
                if(ll flow = dfs(e.to, min(pushed, e.cap-e.flow))){
                    e.flow += flow;
                    edges[id^1].flow -=flow;
                    return flow;
                }
            }
        }
        return 0LL;
    }
    ll max_flow(){
        ll tot_flow=0;
        while(bfs()){
            fill(ptr.begin(), ptr.end(), 0);
            while(ll pushed = dfs(s, FLOW_INF)){
                tot_flow += pushed;
            }
        }
        return tot_flow;
    }
};
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n; cin>>n;
    int N = 2 + (n<<1),
        offset = n;
    Dinic d(N, 0, N-1);
    for(int i=1; i<=n; i++){
        d.add_edge(0, i, 1);
        d.add_edge(offset + i, N-1, 1);   
        string s; cin>>s;
        for(int j=1; j<=n; j++){
            if(s[j-1]=='o'){
                d.add_edge(i, offset + j, (n<<1));
            }
        }
    }
    ll ans = d.max_flow();
    cout<<ans<<'\n';
    for(int i=1; i<=n; i++){
        if(d.level[i] == -1){
            cout<<"1 "<<i<<'\n';
        }
        if(d.level[i+offset] != -1){
            cout<<"2 "<<i<<'\n';
        }
    }
    
}
