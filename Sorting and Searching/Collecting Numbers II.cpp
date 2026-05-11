#include<bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n, m; cin>>n>>m;
    vector<int> a(n+1), pos(n+1);
    for(int i=1; i<=n; i++){
        int x; cin>>x;
        pos[x] = i;
        a[i] = x;
    }
    int ans = 1;
    for(int i=1; i<n; i++){
        if(pos[i] > pos[i+1]) ans++;
    }
    while(m--){
        int i, j; cin>>i>>j;
        int ni = a[i], nj = a[j];
        set<pair<int,int>> s;
        if(ni + 1 <= n){
            s.emplace(ni, ni+1);
        }
        if(ni - 1 >= 1){
            s.emplace(ni-1, ni);
        }
        if(nj + 1 <= n){
            s.emplace(nj, nj+1);
        }
        if(nj - 1 >= 1){
            s.emplace(nj-1, nj);
        }
        for(auto &[a, b]: s){
            if(pos[a]>pos[b])ans--;
        }
        swap(a[i], a[j]);
        pos[ni] = j;
        pos[nj] = i;
        for(auto &[a, b]: s){
            if(pos[a]>pos[b])ans++;
        }
        cout << ans<<'\n';
    }
}
