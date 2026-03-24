// Time Complexity: V^2 E
#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using vll=vector<ll>;
#define fori(i,a,b) for(int i =a; i<b;i++)
#define eb emplace_back
#define sz(a)(int)a.size()
#define rz resize
#define all(a) a.begin(), a.end()
const ll INF = LLONG_MAX;
ll n, m, s, t;
vector<vll> adj;
struct Edge{ ll from,to,cap,flow; };
vector<Edge> edges;
vll d, pt;
void addEdge(ll from, ll to, ll cap){
    if (from != to){
        edges.eb(Edge{from,to,cap,0});
        adj[from].eb(sz(edges)-1);
        edges.eb(Edge{to,from,0,0});
        adj[to].eb(sz(edges)-1);
    }
}
bool bfs() {
    queue<ll> q({s});
    fill(all(d), n+1); d[s]=0;
    while(!q.empty()){
        ll cur = q.front();q.pop();
        if (cur==t) break;
        for(ll k : adj[cur]){
            Edge & e = edges[k];
            if (e.cap > e.flow && d[e.from]+1 < d[e.to]){
                d[e.to] = d[e.from]+1;
                q.push(e.to);
            }
        }
    }
    return d[t] != n+1;
}
ll dfs(ll u, ll flow=INF){
    if (u==t || flow==0) return flow;
    for (ll &i = pt[u]; i < sz(adj[u]); ++i){
        Edge &e = edges[adj[u][i]], &oe = edges[adj[u][i]^1];
        if (d[e.from]+1==d[e.to]){
            if (ll pushed = dfs(e.to, min(flow, e.cap-e.flow))){
                e.flow += pushed;
                oe.flow -= pushed;
                return pushed;
            }
        }
    }
    return 0;
}
ll max_flow(){
    ll totflow =0;
    while(bfs()){
        fill(all(pt), 0);
        while(ll flow = dfs(s)) totflow += flow;
    }
    return totflow;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    cin>>n>>m;
    adj.rz(n), d.rz(n), pt.rz(n);
    fori(i,0,m){
        ll a, b, c; cin>>a>>b>>c;
        --a,--b;
        addEdge(a,b,c);
    }
    s=0, t=n-1;
    cout<<max_flow()<<'\n';
    return 0;
}