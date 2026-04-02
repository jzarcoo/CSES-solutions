#include<bits/stdc++.h>
using namespace std;

typedef unsigned long long ll;

#define eb emplace_back
#define all(z) z.begin(), z.end()

const int N = 1e5;
const int LOG = 20;

struct Edge{
    int a, b, w, i;
    bool inMST=0;
    Edge(int a, int b, int w, int i) : a(a), b(b), w(w), i(i) {}
    bool operator<(const Edge & x) const{
        return w < x.w;
    }
};

int n, m;
ll w_mst = 0;
vector<Edge> edges;
int len[N+1], pa[N+1], depth[N+1];
int up[N+1][LOG], max_edge[N+1][LOG];
vector<pair<int,int>> mst[N+1];

int get(int x){return pa[x]==x?x:pa[x]=get(pa[x]);}
bool comb(int x, int y){
    x=get(x), y=get(y);
    if(x==y) return 0;
    if(len[x]<len[y]) swap(x,y);
    len[x]+=len[y];
    pa[y]=x;
    return 1;
}

void dfs(int v, int p, int d, ll w){
    depth[v] = d;
    up[v][0] = p;
    max_edge[v][0] = w;
    for(int i=1; i<LOG; i++){
        int prev = up[v][i-1];
        up[v][i] = up[prev][i-1];
        max_edge[v][i] = max(max_edge[v][i-1], max_edge[prev][i-1]);
    }
    for(auto &[to, w_to] : mst[v]){
        if(to != p){
            dfs(to, v, d+1, w_to);
        }
    }
}

int get_maxa(int a, int b){
    if(depth[a]<depth[b]) swap(a, b);
    int r=0, k = depth[a]- depth[b];
    for(int p=0; p<LOG; p++){
        if(k & (1<<p)){
            r = max(r, max_edge[a][p]);
            a = up[a][p];
        }
    }
    if(a==b) return r;
    for(int p=LOG-1; p>=0; p--){
        if(up[a][p] != up[b][p]){
            r = max({r, max_edge[a][p], max_edge[b][p]});
            a = up[a][p], b = up[b][p];
        }
    }
    r = max({r, max_edge[a][0], max_edge[b][0]});
    return r;
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin>>n>>m;
    fill(len, len+n+1, 1);
    iota(pa, pa+n+1, 0);
    for(int i=0, a, b, w; i<m; i++){
        cin>>a>>b>>w;
        edges.eb(a,b,w,i);
    }
    sort(all(edges));
    for(Edge &e  : edges){
        if(comb(e.a, e.b)){
            mst[e.a].eb(e.b, e.w);
            mst[e.b].eb(e.a, e.w);
            w_mst += e.w;
            e.inMST = 1;
        }
    }
    dfs(1, 1, 0, 0);
    vector<ll> ans(m);
    for (auto &[a,b,w,i, flag] :edges){
        if(flag){
            ans[i] = w_mst;
        }else{
            int maxa = get_maxa(a, b);
            ans[i] = w_mst - maxa + w;
        }
    }
    for(ll &x : ans) cout <<x <<'\n';
}
