#include<bits/stdc++.h>
using namespace std;
const int N = 2e5;
int n, k;
vector<int> tree[N];
bool processed[N];
int len[N];

long long cnt_depth[N];
long long ans=0;
int mx_depth=0;

int dfsize(int v, int p=-1){
    int &s = len[v] = 1;
    for(int w: tree[v]){
        if(w==p||processed[w]) continue;
        s+=dfsize(w, v);
    }
    return s;
}

int dfcentroid(int v, int tam, int p=-1){
    for(int w : tree[v]){
        if (processed[w] || w==p) continue;
        if((len[w]<<1) > tam)
            return dfcentroid(w, tam, v);
    }
    return v;
}

void cuenta(int v, int p = -1, int d = 1){
    cnt_depth[d]++;
    mx_depth = max(mx_depth, d);
    for(int to: tree[v]){
        if (to == p || processed[to]) continue;
        cuenta(to, v, d+1);
    }
}

void suma(int v, int p=-1, int d=1){
    if(k-d>=0)
        ans += cnt_depth[k-d];
    for(int to: tree[v]){
        if (to == p || processed[to]) continue;
        suma(to, v, d+1);
    } 
}

void build(int v=0){
    int x = dfsize(v);
    int c = dfcentroid(v, x);
    cnt_depth[0]=1;
    mx_depth=0;
    for(int to : tree[c]){
        if (processed[to]) continue;
        suma(to,c);
        cuenta(to,c);
    }
    fill(cnt_depth, cnt_depth+mx_depth+1, 0);
    processed[c] = 1;
    for(int to: tree[c]){
        if (processed[to]) continue;
        build(to);
    }
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin>>n>>k;
    for(int i=1; i<n; i++){
        int a, b; cin>>a>>b; --a,--b;
        tree[a].emplace_back(b);
        tree[b].emplace_back(a);
    }
    build();
    cout<<ans;
}
