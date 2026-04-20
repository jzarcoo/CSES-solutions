#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXLEN = 1e5;
struct state{
    int len, link;
    map<char, int> next;
};
state st[MAXLEN*2];
ll dp[MAXLEN*2];
bool vis[MAXLEN*2];
int sz = 0, last;
void sa_init(){
    st[0].len=0;
    st[0].link = -1;
    sz++;
    last = 0;
}
void sa_extend(char c){
    int cur = sz++;
    st[cur].len = st[last].len + 1;
    int p = last;
    while(p != -1 && !st[p].next.count(c)){
        st[p].next[c] = cur;
        p = st[p].link;
    }
    if(p==-1){
        st[cur].link  = 0;
    }else{
        int q = st[p].next[c];
        if(st[p].len + 1 == st[q].len){
            st[cur].link = q;
        }else{
            int clone = sz++;
            st[clone].len = st[p].len + 1;
            st[clone].next = st[q].next;
            st[clone].link = st[q].link;
            while(p!=-1 && st[p].next[c]==q){
                st[p].next[c] = clone;
                p = st[p].link;
            }
            st[q].link = st[cur].link = clone;
        }
    }
    last = cur;
}
ll dfs(int v){
    if(vis[v]) return dp[v];
    vis[v] = 1;
    ll &r = dp[v] = 0;
    for(auto [c, u] : st[v].next){
        r += 1 + dfs(u);        
    }
    return r;
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    string s; cin>>s;
    sa_init();
    for(char c: s){
        sa_extend(c);
    }
    dfs(0);
    string ans = "";
    ll k; cin>>k;
    int v = 0;
    while(k>0){
        for(char c = 'a'; c <= 'z'; c++){
            if(!st[v].next.count(c)) continue;
            int u = st[v].next[c];
            ll r = 1 + dp[u];
            if(k>r){
                k-=r;
            }else{
                ans += c;
                k--;
                v = u;
                break;
            }
        }
    }
    cout << ans<<'\n';
}
