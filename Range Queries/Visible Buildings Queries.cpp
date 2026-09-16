#include<bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
const int N=1e5+5;
const int LOG = 19;
int up[N][LOG+1];
int n, q;
vi height;
void solve(){
    stack<int> st;
    for(int i=0; i<n; i++){
        int h = height[i];
        while(!st.empty() && height[st.top()] < h){
            up[st.top()+1][0] = i+1;
            st.pop();
        }
        st.push(i);
    }
    for(int i=1; i<=n+1; i++){
        if(up[i][0]==0) up[i][0] = n+1;
    }
    for(int lvl = 1; lvl <= LOG; lvl++){
        for(int i=1; i<=n+1; i++){
            up[i][lvl] = up[up[i][lvl-1]][lvl-1];
        }
    }
}
int query(int l, int r){
    int ans = 1;
    int cur = l;
    for(int i=LOG; i>=0; i--){
        if(up[cur][i] <= r){
            cur = up[cur][i];
            ans += 1 << i;
        }
    }
    return ans;
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin>>n>>q;
    height = vi(n);
    for(auto &i:height)cin>>i;
    solve();
    while(q--){
        int l, r; cin>>l>>r;
        cout << query(l, r)<<'\n';
    }
}

