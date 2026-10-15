#include<bits/stdc++.h>
using namespace std;

typedef pair<int,int> ii;
typedef vector<int> vi;

#define pb push_back
#define rep(i,n) for(int i=0; i<n; i++)
#define fore(i,a,b) for(int i=a; i<=b; i++)

const int MAXN = 2500 + 1;

int n,m,q;
vi g[MAXN];
int dist[MAXN][MAXN][2];

void bfs(int v){

    dist[v][v][0] = 0;
    queue<ii> q({make_pair(v, 0)});

    while(!q.empty()){
        auto [at, parity] = q.front(); q.pop();
        int d = dist[v][at][parity];
        for(int to : g[at]){
            if(dist[v][to][1-parity] == -1){
                dist[v][to][1-parity] = 1+d;
                q.emplace(to, 1-parity);
            }
        }
    }

}
void solve(){
    memset(dist, -1, sizeof dist);

    fore(v, 1, n){
        bfs(v);
    }
}

void query(){
    int a, b, steps; cin>>a>>b>>steps;
    int &d = dist[a][b][steps & 1];
    if(d!=-1 && d <=steps){
        cout << "YES\n";
    }else{
        cout << "NO\n";
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m>>q;
    rep(ie,m){
        int a, b; cin>>a>>b;
        g[b].pb(a);
        g[a].pb(b);
    }
    solve();
    while(q--){
        query();
    }
}
