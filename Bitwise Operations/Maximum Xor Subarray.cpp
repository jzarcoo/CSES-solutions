#include<bits/stdc++.h>
using namespace std;
const int MAXN = 9e6;
struct node{
    int ch[2];
    int val;
    node()
    {
        fill(ch, ch+2, -1);
    }
} trie[MAXN];
int root = 0;
int cnt = 1;
int add(int i, int v){
    if(trie[i].ch[v] == -1){
        trie[i].ch[v] = cnt;
        cnt++;
    }
    return trie[i].ch[v];
}
void insert(int num)
{
    int cur = root;
    for(int i=30; i>=0; i--){
        int x = (num>>i) & 1;
        cur = add(cur, x);
    }
    trie[cur].val = num;
}
int query(int num){
    int cur = root;
    for(int i=30; i>=0; i--){
        int x = (num>>i) & 1;
        if(trie[cur].ch[1-x] != -1){
            cur = trie[cur].ch[1-x];
        }else if (trie[cur].ch[x]!=-1){
            cur  = trie[cur].ch[x];
        }
    }
    return num ^ trie[cur].val;
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n; cin>>n; vector<int> a(n); for(auto &i:a) cin>>i;
    insert(0);
    int ans = INT_MIN;
    int prefix = 0;

    for(int x: a){
        prefix ^= x;
        ans = max(ans, query(prefix));
        insert(prefix);
    }

    cout << ans <<'\n';    
}
