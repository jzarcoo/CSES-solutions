#include<bits/stdc++.h>
using namespace std;
const int INF = 1e9;
bool ckmin(int &a, int b){
    return b<a?a=b,1:0;
}
template<int V, int E>
struct MCF{
    int N, m=0, s, t;
    int flow[E*2], cap[E*2], cost[E*2];
    int to[E*2], nx[E*2];
    int hd[V];
    int pi[V], d[V], p[V], vis[V], inq[V];
    MCF(int n, int s, int t)
    : N(n), s(s), t(t) {
        memset(hd, -1, sizeof hd);
        memset(flow, 0, sizeof flow);
    }
    void add_arc(int a, int b, int u, int c){
        nx[m] = hd[a], hd[a] = m;
        to[m] = b, cost[m] = c, cap[m] = u;
        m++;
    }
    void setpi(){
        fill(pi, pi+N, INF);
        memset(vis, 0, sizeof vis);
        memset(inq, 0, sizeof inq);
        queue<int> q; q.push(s); pi[s]=0; inq[s] = 1;
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
        bool operator>(state s) const{ return d > s.d; }
    };
    void dijk(){
        fill(d, d+N, INF);
        memset(p, -1, sizeof p);
        memset(vis, 0, sizeof vis);        
        priority_queue<state, vector<state>, greater<state>> pq;
        pq.push({s,0});
        d[s] = 0;
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
    int mincost(int F){
        setpi();
        int C = 0;
        while(F>0){
            dijk();
            if(d[t] == INF) return INF;
            int f = F,
                c = d[t] + pi[t] - pi[s];
            for (int x = t; x != s; x = to[p[x]^1]){
                ckmin(f, cap[p[x]] - flow[p[x]]);
            }
            C += c * f;
            F-=f;
            for(int x = t; x != s; x = to[p[x]^1]){
                flow[p[x]] += f;
                flow[p[x]^1] -= f;
            }
            for(int i=0; i<N; i++){
                if(d[i]<INF){
                    pi[i] += d[i];
                }
            }
        }
        return C;
    }
};
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n, m, k; cin>>n>>m>>k;
    MCF<500, 1000> mcf(n, 0, n-1);
    for(int i=0, a,b,u,c;  i<m; i++){
        cin>>a>>b>>u>>c;
        mcf.add_arc(--a,--b,u,c);
        mcf.add_arc(b,a,0,-c);
    }
    int r = mcf.mincost(k);
    if(r==INF) r=-1;
    cout << r << '\n';
}

