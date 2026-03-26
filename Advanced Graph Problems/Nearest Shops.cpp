#include<bits/stdc++.h>
using namespace std;

const int N=1e5;
const int INF = INT_MAX;

vector<int> adj[N];
bool isAnime[N];
int d[2][N], p[2][N];

int n, m, k;

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin>>n>>m>>k;
    memset(d, -1, sizeof d);
    memset(p, -1, sizeof p);
    queue<pair<int,int>> q;
    for(int i=0; i<k; i++){
        int x; cin>>x;--x;
        isAnime[x]=1;
        q.emplace(x,0);
        d[0][x] = 0;
        p[0][x] = x;
    }
    for(int i=0; i<m; i++){
        int a, b; cin>>a>>b;--a,--b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    while(!q.empty()){
        auto [at, t] = q.front(); q.pop();
        for(int to : adj[at]){
            int nd = d[t][at] + 1,
                pa = p[t][at];
            if(d[0][to]==-1){
                d[0][to] = nd;
                p[0][to] = pa;
                q.emplace(to, 0);
            }else if(d[1][to]==-1 && p[0][to] != pa){
                d[1][to] = nd;
                p[1][to] = pa;
                q.emplace(to, 1);
            }
        }
    }
    for(int v=0; v<n; v++){
        int ans = INF;
        if(p[0][v] != v && d[0][v]!=-1){
            ans =min(ans, d[0][v]);
        }
        if(d[1][v]!=-1){
            ans =min(ans, d[1][v]);
        }
        cout << ((ans==INF) ? -1 : ans) <<' ';
    }
}
