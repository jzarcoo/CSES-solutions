#include<bits/stdc++.h>
using namespace std;
typedef int64_t i64;
typedef vector<i64> vi;
 
const int N = 2e5+5;
const int LOG = 19;
 
int up[2*N][LOG+1];
 
int n;
i64 k;
vi v;
 
void solve(){
    i64 s = 0;
    for(int l=0, r=0; l<2*n; l++){
        while(r < 2*n && s+v[r]<=k){
            s+=v[r++];
        }
        up[l][0] = r;
        s-=v[l];
    }
    up[2*n][0] = 2*n;
    /*
    for(int i=0; i<n; i++){
        cout << i << ' ' << up[i][0]<<endl;
    }
    */
 
    for(int lvl=1; lvl<=LOG; lvl++){
        for(int i=0; i<=2*n; i++){
            up[i][lvl] = up[up[i][lvl-1]][lvl-1];
        }
    }
 
    int ans = n;
    for(int i=0; i<n; i++){
        int jumps = 0;
        int pos = i;
        for(int lvl=LOG; lvl>=0; lvl--){
            if(up[pos][lvl] - i < n){
                jumps += (1<<lvl);
                pos = up[pos][lvl];
            }
        }
        ans = min(ans, jumps + 1);
    }
    cout << ans << '\n';
}
 
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin>>n>>k;
    v = vi(2*n+1);
    for(int i=0; i<n; i++){
        cin>>v[i];
        v[i+n] = v[i];
    }
    solve();
}
