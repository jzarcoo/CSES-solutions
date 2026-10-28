#include<bits/stdc++.h>
using namespace std;

const int N = 16;
const int T = 1 << N;

int is[T], chi[T], p[T];

int n, m;
int g[N], color[N];

void solve(){
    int npot = 1 << n;
    is[0] = 1;
    for(int mask = 1; mask < npot; mask++){
        int lb = mask & -mask;
        int v = __builtin_ctz(lb);
        int prev = mask ^ lb;
        if(is[prev] == 1 && (g[v] & prev) == 0){
            is[mask] = 1;
        }
    }
    fill(chi, chi + npot, INT_MAX);
    chi[0] = 0;
    for(int mask = 1; mask < npot; mask++){
        int lb = mask & -mask;
        int v = __builtin_ctz(lb);
        int del = mask ^ lb;
        // vertices independientes de mask con v
        int m = del & ~g[v];
        for(int sub = m; ; sub = (sub-1) & m){
            if(is[sub]){
                int prev = del ^ sub;
                if(chi[mask] > chi[prev] + 1){
                    chi[mask] = 1 + chi[prev];
                    p[mask] = prev;
                }
            }
            if(sub==0) break;
        }
    }
    cout << chi[npot - 1] << '\n';
    int curr = npot -1;
    for(int c=1; c <= chi[npot-1]; c++){
        int parent = p[curr];
        int mask = curr & ~parent;
        for(int j=0; j<n; j++){
            if (mask & (1<<j)){
                color[j] = c;
            }
        }
        curr = parent;
    }
    for(int i=0; i<n; i++){
        cout << color[i]<<" \n"[i+1==n];
    }

}
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin>>n>>m;
    for(int i=0,a,b; i<m; i++){
        cin>>a>>b;--a,--b;
        g[a] |= 1<<b;
        g[b] |= 1<<a;
    }
    solve();
}
