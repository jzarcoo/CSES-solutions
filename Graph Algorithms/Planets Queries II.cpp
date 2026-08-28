#include<bits/stdc++.h>
using namespace std;
const int N = 2e5;
int p[N+1]; // succesor
int n, Q;


int indeg[N+1];
int vis[N+1];
int pos_cycle[N+1]; // cycle
int comp[N+1]; // weak
int cycle[N+1];
int depth[N+1];
int len_cycle[N+1];

int num_cycles = 0;

const int LOG=20;
int up[N+1][LOG+1];


void dfs(int v){
    vis[v] = 1;
    int nxt = p[v];
    // cycle
    if(vis[nxt]==1){
        num_cycles++;
        // nxt -> ... -> v -> nxt
        int num_vertices = 0;
        for(int i=nxt; 1; i = p[i]){
            pos_cycle[i] = ++num_vertices;
            cycle[i] = num_cycles;
            comp[i] = num_cycles;
            if(p[i] == nxt) break;
        }
        for(int i=nxt; 1; i=p[i]){
            len_cycle[i] = num_vertices;
            if(p[i]==nxt) break;
        }
    }else if(vis[nxt] == 0){
        //cout << "nxt: "<<nxt<<endl;
        dfs(nxt);
    }
    //cout << "v: "<<v<<endl;
    vis[v] = 2;
}

int kth(int v, int k){
    int at = v;
    for(int i=0; i<=LOG; i++){
        if((k &(1<<i))!=0){
            at = up[at][i];
        }
    }
    return at;
}
int cycle_case(int a, int b){
    if(a==b){
        return 0;
    }
    if(pos_cycle[a] < pos_cycle[b]){
        return pos_cycle[b]-pos_cycle[a];
    }else{
        return len_cycle[a] + pos_cycle[b]-pos_cycle[a];
    }
}
int solve(int a, int b){
    if(a==b){
        return 0;
    }
    if(comp[a]!= comp[b]){
        //cout<<"diff: " << a << ' '<<b<<endl;
        return -1;
    }
    // cycle
    if(cycle[a] == cycle[b] && cycle[a]!=0){
        //cout<<"cyc: " << a << ' '<<b<<endl;
        return cycle_case(a, b);
    }
    //tree
    if(cycle[a]==0 && cycle[b]==0){
        //cout<<"tree: " << a << ' '<<b<<endl;
        if(depth[b] >= depth[a]){
            return -1;
        }
        int k = depth[a]-depth[b];
        int ancestor = kth(a, k);
        if(ancestor == b){
            return k;
        }else{
            return -1;
        }
    }
    if(cycle[a]==0){
        //cout<<"tree cyc: " << a << ' '<<b<<endl;
        // b cycle
        int first = kth(a, depth[a]);
        //cout << depth[a]<<' '<<first <<' ' << b<<endl;
        int res = cycle_case(first, b);
        return res + depth[a];
    }
    return -1;
}

void solve(){
    queue<int> q;
    for(int i=1;i<=n; i++){
        if(vis[i]==0){
            dfs(i);
        }
        if(indeg[i]==0){
            q.push(i);
        }
    }
    vector<int> topo;
    while(!q.empty()){
        int v = q.front(); q.pop();
        topo.push_back(v);
        if(--indeg[p[v]] == 0){
            q.push(p[v]);
        }
    }
    for(int i=topo.size()-1; i>=0; i--){
        int v = topo[i];
        comp[v] = comp[p[v]];
        depth[v] = 1 + depth[p[v]];
    }

    for(int v=1; v<=n; v++){
        if(cycle[v]!=0){
            up[v][0] = v;
        }else{
            //cout << v<<' ';
            up[v][0] = p[v];
        }
    }
    for(int i=1; i<=LOG; i++){
        for(int v=1; v<=n; v++){
            up[v][i] = up[up[v][i-1]][i-1];
        }
    }
    // QUERY
    for(int i=0; i<Q; i++){
        int a, b; cin>>a>>b;
        cout<< solve(a, b)<<'\n';
    }
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin>>n>>Q;
    for(int i=1; i<=n; i++){
        cin>>p[i];
        indeg[p[i]]++;
    }
    solve();
}
