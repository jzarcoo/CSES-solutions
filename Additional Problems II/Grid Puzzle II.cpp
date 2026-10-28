#include<bits/stdc++.h>
using namespace std;

const int INF = 1e9;
const int MX_C = 1000;
const int N  = 50;

int rows[N], cols[N];
int coins[N][N];
int n;

bool ckmin(int &a, int b){
    return b < a ? a=b, 1 : 0;
}

template<int V, int E>
struct MCF{
    int N, M = 0, S, T;
    int flow[E*2], cap[E*2], cost[E*2];
    int to[E*2], nx[E*2];
    int hd[V];
    int pi[V], d[V], p[V], vis[V], inq[V];
    void init(int n, int s, int t){
        N=n, S = s, T=t;
        memset(hd, -1, sizeof hd);
        memset(flow, 0, sizeof flow);
    }
    void _arc(int a, int b, int u, int c){
        nx[M] = hd[a], hd[a] = M;
        to[M] = b, cost[M] = c, cap[M] = u;
        M++;
    }
    void add_arc(int a, int b, int u, int c){
        _arc(a, b, u, c);
        _arc(b, a, 0, -c);
    }
    void setpi(){
        memset(vis, 0, sizeof vis);
        memset(inq, 0, sizeof inq);
        fill(pi, pi+N, INF);
        queue<int> q; q.push(S); pi[S] =0; inq[S] = 1;
        for(int n; !q.empty();){
            n = q.front(); q.pop(); inq[n] = 0;
            for(int id=hd[n], x; ~id; id = nx[id]){
                if(cap[id]>flow[id]){
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
        bool operator>(state o) const {
            return d > o.d;
        }
    };
    void dijk(){
        fill(d, d+N, INF);
        memset(p, -1, sizeof p);
        memset(vis, 0, sizeof vis);
        priority_queue<state, vector<state>, greater<state>> pq;
        pq.push({S, 0}); d[S] = 0;
        for(int n; !pq.empty();){
            n = pq.top().n; pq.pop(); 
            if(vis[n]) continue;
            vis[n] = 1;
            for(int id = hd[n], x, w; ~id; id = nx[id]){
                if(cap[id]>flow[id]){
                    x = to[id];
                    w = cost[id] + pi[n] - pi[x];
                    if(ckmin(d[x], d[n] + w)){
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
            int c = d[T] + pi[T] - pi[S], f = INF;
            for(int x = T; x != S; x = to[p[x]^1]) {
                ckmin(f, cap[p[x]] - flow[p[x]]);
            }
            C += c * f;
            for(int x = T; x!= S; x = to[p[x]^1]){
                flow[p[x]] += f;
                flow[p[x]^1] -=f;
            }
            F += f;
            for(int i=0; i<N; i++){
                if(d[i] < INF){
                    pi[i] += d[i];
                }
            }
        }
        return {F, C};
    }
};

void solve(){
    int marked = accumulate(rows, rows + n, 0);
    int V = 2*n+2, S=0, T=V-1;
    // V: 2*50+2
    // E: 50*50 + 50 + 50
    MCF<102, 2600> mcf;
    mcf.init(V, S, T);
    for(int r=1; r<=n; r++){
        mcf.add_arc(S, r, rows[r-1], 0);
    }
    for(int c=1; c<=n; c++){
        mcf.add_arc(n+c, T, cols[c-1], 0);
    }
    for(int r=1; r<=n; r++){
        for(int c=1; c<=n; c++){
            mcf.add_arc(r, n+c, 1, MX_C - coins[r-1][c-1]);
        }
    }
    auto [max_flow, min_cost] = mcf.mincost_maxflow();
    // cout << max_flow << endl;
    if(max_flow != marked){
        cout << -1 << '\n';
        return ;
    }
    int r = max_flow * MX_C - min_cost;
    cout << r << '\n';
    vector<string> grid(n, string(n, '.'));
    for(int r = 1; r<=n; r++){
        for(int id = mcf.hd[r], c; ~id; id = mcf.nx[id]){
            c = mcf.to[id];
            if(n+1 <= c && c <= 2*n &&
                mcf.flow[id] == 1){
                grid[r-1][c-n-1] = 'X';
            }
        }
    }
    for(string s : grid){
        cout << s << '\n';
    }
}

int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    cin>>n;
    for(int i=0; i<n; i++){
        cin>>rows[i];
    }
    for(int i=0; i<n; i++){
        cin>>cols[i];
    }
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin>>coins[i][j];
        }
    }
    solve();
}
