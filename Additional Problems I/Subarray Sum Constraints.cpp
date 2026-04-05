#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> ii;
const int N=5e3+1;
vector<ii> g[N];
ll pref[N];
int n, m;
bool dfs(int v){
    for(auto &[vecino, val] : g[v]){
        if(pref[vecino]==-1){
            pref[vecino] = pref[v] + val;
            if(!dfs(vecino)) return 0;
        }else if(pref[vecino] != pref[v] + val){
            return 0;
        }
    }
    return 1;
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin>>n>>m;
    while(m--){
        int l, r, s; cin>>l>>r>>s;
        g[r].emplace_back(l-1, -s);
        g[l-1].emplace_back(r, s);
    }
    fill(pref, pref+n+1, -1);
    for(int v=0; v<=n;v++){
        if (pref[v]==-1){
            pref[v]=0;
            if(!dfs(v)){
                cout<<"NO\n";
                return 0;
            }
        }
    }
    cout<<"YES\n";
    for(int i=1; i<=n; i++){
        cout << pref[i]-pref[i-1] <<' ';
    }
    
}
