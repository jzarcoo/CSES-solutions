#include<bits/stdc++.h>
using namespace std;
#pragma GCC target("popcnt")
const int N=1e5;
int len[N+1], pa[N+1];
int get(int x){
    return pa[x]==x ? x : pa[x] = get(pa[x]);
}
void comb(int a, int b){
    a = get(a); b=get(b);
    if(a==b) return;
    if(len[a]<len[b]) swap(a, b);
    len[a] += len[b];
    pa[b]=a;
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n, m; cin>>n>>m;
    fill(len, len+n+1, 1);
    iota(pa, pa+n+1, 0);
    for(int i=0,a,b; i<m; i++){
        cin>>a>>b;
        comb(a,b);
    }
    unordered_map<int,int> tam;
    for(int v=1; v<=n; v++){
        if(pa[v]==v){
            tam[len[v]]++;
        }
    }
    bitset<N+1> b; b[0]=1;
    for(auto [sz, cnt] : tam){
        for(int pot=1; cnt; pot<<=1){
            int take = min(pot, cnt);
            b |= b << (take*sz);
            cnt -= take;
        }
    }
    for(int i=1; i<=n; i++){
        cout << (b[i] ? '1':'0');
    }
}
