#include<bits/stdc++.h>
using namespace std;

const int INF = 1e9;
const int MN = 200;

bool ckmin(int &a, int b){return b<a?a=b,1:0;}

template<int V, int E>
struct MCF{
    int N, M=0, S, T;
    int flow[E*2], cap[E*2], cost[E*2];
    int nx[E*2], to[E*2];
    int hd[V];
    int pi[V], p[V], d[V], vis[V], inq[V];
    MCF(int n, int s, int t)
    : N(n), S(s), T(t) {
        memset(flow, 0, sizeof flow);
        memset(hd, -1, sizeof hd);
    }
    void _add(int a, int b, int u, int c){
        nx[M] = hd[a], hd[a] = M;
        to[M] = b, cap[M] = u, cost[M] = c;
        M++;
    }
    void add_arc(int a, int b, int u, int c) {
        _add(a, b, u, c);
        _add(b, a, 0, -c);
    }
    void setpi(){
        memset(vis, 0, sizeof vis);
        memset(inq, 0, sizeof inq);
        fill(pi, pi+N, INF);
        queue<int> q;
        q.push(S); pi[S] = 0; inq[S] = 1;
        for(int n; !q.empty(); ){
            n = q.front(); q.pop(); inq[n] = 0;
            for(int id = hd[n], x; ~id; id = nx[id]){
                if(cap[id] > flow[id]){
                    x = to[id];
                    if(ckmin(pi[x], pi[n] + cost[id])){
                        if(!inq[x]){
                            q.push(x);
                            inq[x] = 1;
                            assert(++vis[x] <= N);
                        }
                    }
                }
            }
        }
    }
    struct state{
        int n, d;
        bool operator>(state s) const {return d> s.d;}
    };
    void dijk(){
        fill(d, d+N, INF);
        memset(vis, 0, sizeof vis);
        memset(p, -1, sizeof p);
        priority_queue<state, vector<state>, greater<state>> pq;
        pq.push({S, 0});
        d[S] = 0;
        for(int n; !pq.empty();){
            n = pq.top().n; pq.pop();
            if(vis[n]) continue;
            vis[n] = 1;
            for(int id = hd[n], x, w; ~id; id = nx[id]){
                if(cap[id] > flow[id]){
                    x = to[id];
                    w = cost[id] + pi[n] - pi[x];
                    if(ckmin(d[x], w + d[n])){
                        p[x] = id;
                        pq.push({x, d[x]});
                    }
                }
            }
        }
    }
    pair<int, int> mincost_maxflow(){
        setpi();
        int C = 0, F = 0;
        while(true){
            dijk();
            if(d[T] == INF) break;
            int f = INF,
                c = d[T] + pi[T] - pi[S];
            for(int x = T; x != S; x = to[p[x]^1]){
                ckmin(f, cap[p[x]] - flow[p[x]]);
            }
            C += c * f;
            F += f;
            for(int x = T; x != S; x = to[p[x]^1]){
                flow[p[x]] += f;
                flow[p[x]^1] -= f;
            }
            for(int i=0; i<N; i++){
                if(d[i] < INF){
                    pi[i] += d[i];
                }
            }
        }
        return {F, C};
    }
};

int n;
int cost[MN][MN];

void solve(){
    int V = 2*n+2, S = 0, T = V-1;
    MCF<MN*2+2, MN*MN + 2*MN> mcf(V, S, T);
    for(int i=0; i<n; i++){
        mcf.add_arc(S, i+1, 1, 0);
        mcf.add_arc(n+i+1, T, 1, 0);
        for(int j=0; j<n; j++){
            mcf.add_arc(i+1, j+1+n, 1, cost[i][j]);
        }
    }
    auto [f, c] = mcf.mincost_maxflow();
    if(f!=n){
        cout << -1 <<'\n';
        return;
    }
    cout << c << '\n';
    for(int e = 1; e<=n; e++){
        for(int id = mcf.hd[e], x; ~id; id = mcf.nx[id]){
            x = mcf.to[id];
            x-=n;
            if(1 <= x && x <= n && 
                mcf.flow[id] == 1){
                cout << e << ' '<<x << '\n';
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin>>n;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin>>cost[i][j];
        }
    }
    solve();
}
