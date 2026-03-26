#include<bits/stdc++.h>
using namespace std;
const int N=15;
vector<int> adj[1<<(N-1)];
int n;
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin>>n;
    int mask = 1<<(n-1);
    for(int v=0; v<mask; v++){
        int next = (v<<1) & (mask-1);
        adj[v].emplace_back(next);
        adj[v].emplace_back(next|1);
    }
    stack<int> st;
    st.push(0);
    string ans;
    while(st.size()){
        int v = st.top();
        if (adj[v].empty()){
            ans += (v & 1) + '0';
            st.pop();
        }else{
            st.push(adj[v].back());
            adj[v].pop_back();
        }
    }
    ans.pop_back();
    string tail(n-1, '0');
    cout<<ans<<tail;
}
