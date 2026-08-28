#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll,ll> pll;
typedef vector<pll> vpll;

typedef vector<int> vi;

#define pb push_back
#define all(z) z.begin(), z.end()

const int N = 1e5+5;

int s, t;
int n, m;
vpll g[N];

ll d[N];
int p[N];

//vpll rev[N];
vpll adj[N];
bool vis[N];
vi cutpoints;
int low[N], tin[N], timer = 0;

void dijkstra(){
    fill(d, d+N, LLONG_MAX);
    fill(p, p+N, -1);
    d[s] = 0;
    priority_queue<pll, vpll, greater<pll>> pq;
    pq.emplace(0, s);
    while(!pq.empty()){
        auto [l, v] = pq.top(); pq.pop();
        if (d[v] < l) continue;
        /*
        if(v != s) {
            ll w = l - d[p[v]];
            cout << p[v] << ' ' <<v <<  ' ' <<w<<endl;
            adj[p[v]].emplace_back(v, w);
            adj[v].emplace_back(p[v], w);
        }
        */
        for(auto &[to, w] : g[v]){
            ll nxt = l + w;
            if(nxt < d[to]){
                d[to] = nxt;
                p[to] = v;
                pq.emplace(nxt, to);
            }
        }
    }
}

void dfs(int v, int p){
    low[v] = tin[v] = ++timer;
    for(auto &[to, w] : adj[v]){
        if(to==p){
            continue;
        }
        if(tin[to]){
            low[v] = min(low[v], tin[to]);
        }else{
            dfs(to, v);
            low[v] = min(low[v], low[to]);
            if(low[to] >= tin[v]){
                if(tin[v] > 1 || tin[to] > 2){
                    cutpoints.pb(v);
                }
            }
        }
    }
}


bool paths(int v){
    if(vis[v]) return adj[v].size()  > 0;
    if(v==t) return true;
    vis[v] = true;
    bool reachT = false;
    for(auto &[to, w] : g[v]){
        if(d[to] == d[v] + w){
            if(paths(to)){
                adj[v].emplace_back(to, w);
                adj[to].emplace_back(v, w);
                reachT = true;
            }
        }
    }
    return reachT;
}

void build(){
    paths(1);
}

void solve(){
    dijkstra();
    build();
    dfs(1, -1);

    cutpoints.pb(s);
    cutpoints.pb(t);
    sort(all(cutpoints));
    cutpoints.erase(unique(all(cutpoints)), cutpoints.end());
    cout << cutpoints.size() << endl;
    for(int c: cutpoints){
        cout << c <<' ';
    }
    
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin>>n>>m;
    for(int i=0; i<m; i++){
        ll a, b, c;cin>>a>>b>>c;
        g[a].emplace_back(b, c);
        //rev[b].emplace_back(a, c);
    }
    
    s = 1, t = n;

    solve();
}
