#include<bits/stdc++.h>
using namespace std;
const int N=2500;
const int INF = 2*N;
int n, m;
int ans = INF;
vector<int> adj[N];
int d[N];
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin>>n>>m;
    for(int i=0; i<m; i++){
        int a, b; cin>>a>>b;--a,--b;
        adj[a].emplace_back(b);
        adj[b].emplace_back(a);
    }
    for(int v=0; v<n; v++){
        fill(d, d+n, -1);
        queue<int> q;
        q.push(v);
        d[v]=0;
        while(q.size()){
            int at = q.front(); q.pop();
            if(2*d[at]+1 >= ans) continue;
            for(int to : adj[at]){
                if(d[to] == -1){
                    q.push(to);
                    d[to] = 1+d[at];
                }else if (d[to]>=d[at]){
                    ans = min(ans, 1 + d[at] + d[to]);
                }
            }
        }
    }
    cout << ((ans==INF) ? -1 : ans) << '\n';
}
