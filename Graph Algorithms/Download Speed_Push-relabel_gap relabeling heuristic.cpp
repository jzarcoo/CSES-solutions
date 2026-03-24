// V^3
#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using vll=vector<ll>;
#define fori(i,a,b) for(int i=a;i<b;i++)
#define eb emplace_back
#define sz(a) (int)a.size()
ll n,m;
vll excess, dist, active, countt;
queue<ll> Q;
struct Edge{ ll from,to,cap,flow,index;};
vector<vector<Edge>> G;
void addEdge(ll from, ll to, ll cap){
    G[from].eb(Edge{from, to, cap, 0, sz(G[to])});
    if (from ==to) G[from].back().index++;
    G[to].eb(Edge{to, from, 0, 0, sz(G[from])-1});
}
void enqueue(ll v){
    if (!active[v] && excess[v]>0){
        active[v]=true;
        Q.push(v);
    }
}
void push(Edge & e){
    ll amt = min(excess[e.from], e.cap-e.flow);
    if (dist[e.from] <= dist[e.to] || amt==0) return;
    e.flow += amt;
    G[e.to][e.index].flow -=amt;
    excess[e.to] +=amt;
    excess[e.from] -=amt;
    enqueue(e.to);
}
void gap(ll k) {
    fori(v,0,n) {
        if (dist[v] < k) continue;
        countt[dist[v]]--;
        dist[v] = max(dist[v], n + 1);
        countt[dist[v]]++;
        enqueue(v);
    }
}
void relabel(ll v) {
    dist[v] = 2*n;
    countt[dist[v]]--;
    for (auto &e : G[v]) if (e.cap > e.flow) dist[v] = min(dist[v], dist[e.to] + 1);
    countt[dist[v]]++;
    enqueue(v);
}
void discharge(ll v) {
    for (int i=0; excess[v]>0 && i<sz(G[v]); i++) push(G[v][i]);
    if (excess[v] > 0) 
        if (countt[dist[v]] == 1) gap(dist[v]);
        else relabel(v);
}
ll max_flow(ll s, ll t){
    countt[0]=n-1;
    countt[n]=1;
    dist[s]=n;
    active[s]=active[t]=true;
    for(auto &e:G[s]){
        excess[s]+=e.cap;
        push(e);
    }
    while (!Q.empty()) {
        ll v = Q.front(); Q.pop();
        active[v] = false;
        discharge(v);
    }
    ll totflow = 0;
    for (auto &e : G[s]) totflow += e.flow;
    return totflow;
}
int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    cin>>n>>m; G.resize(n); excess.resize(n); dist.resize(n); active.resize(n); countt.resize(2*n);
    fori(i,0,m){
        ll a, b, c; cin>>a>>b>>c; --a,--b;
        addEdge(a,b,c);
    }
    cout<<max_flow(0,n-1)<<'\n';
    return 0;
}