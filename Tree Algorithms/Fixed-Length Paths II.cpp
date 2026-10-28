#include<bits/stdc++.h>
using namespace std;
#define sz(z)(int)z.size()
const int N=2e5;
vector<int> tree[N];
int n, k1, k2;
long long res = 0;
void merge(deque<int> &p, deque<int> &c){
    if(sz(p) < sz(c)) p.swap(c);
    for(int i=0; i<sz(c); i++){
        int vc = c[i] - (i+1>=sz(c) ? 0 : c[i+1]);
        // k2-i
        int up = (k2-i+1 >= sz(p)) ? p[0] : k2-i < 0 ? 0 : p[0] - p[k2-i+1];
        // k1 - i - 1
        int low = (k1-i >= sz(p)) ? p[0] : k1-1-i < 0 ? 0 : p[0] - p[k1-i];
        int vp = up - low;
        res += 1LL * vc * vp;
    }
    for(int i=0; i<sz(c); i++){
        p[i] += c[i];
    }
}
deque<int> dfs(int v, int p){
    // suffix sum
    // cnt[i] num of node at distance d >= i
    deque<int> cnt{1}; 
    for(int to : tree[v]){
        if(to!=p){
            deque<int> cnt_child = dfs(to, v);
            cnt_child.push_front(cnt_child.front());
            merge(cnt, cnt_child);
        }
    }
    return cnt;
}
void solve(){
    dfs(0, 0);
    cout << res << '\n';
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin>>n>>k1>>k2;
    for(int i=1; i<n; i++){
        int a, b; cin>>a>>b; --a,--b;
        tree[a].emplace_back(b);
        tree[b].emplace_back(a);
    }
    solve();
}
