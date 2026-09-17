#include<bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
#define all(z) z.begin(), z.end()
#define sz(z)(int)z.size()
const int N = 1 << 19;
const int NEUTER = INT_MIN;
int tree[N<<1];
int a[N];
set<int> pos[N];
vi v;
vector<vi> queries;
int n, q;
void change(int i, int x){
    for(tree[i+=N] = x; i > 1; i>>=1){
        tree[i>>1] = max(tree[i], tree[i^1]);
    }
}
int query(int l, int r){
    if (l>r) return NEUTER;
    int ans = NEUTER;
    for(l+=N, r+=N; l<= r; l>>=1, r>>=1){
        if(l&1) ans = max(ans, tree[l++]);
        if(!(r&1)) ans = max(ans, tree[r--]);
    }
    return ans;
}
int id(int val){
    return lower_bound(all(v), val) - v.begin() + 1;
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin>>n>>q;
    for(int i=1; i<=n; i++){
        cin>>a[i];
        v.push_back(a[i]);
    }
    for(int i=0; i<q; i++){
        int t; cin>>t;
        if(t==2){
            int l, r; cin>>l>>r;
            queries.push_back({t, l, r});
        }else{
            int k, u; cin>>k>>u;
            queries.push_back({t, k, u});
            v.push_back(u);
        }
    }
    sort(all(v));
    v.erase(unique(all(v)), v.end());
    for(int i=1; i<=n; i++){
        a[i] = id(a[i]);
        int val = a[i];
        tree[i+N] = pos[val].empty() ? 0 : *pos[val].rbegin();
        pos[val].insert(i);
    }
    for(int i=N-1; i>=0; i--) tree[i] = max(tree[i<<1], tree[i<<1 | 1]);
    for(int i=0; i<q; i++){
        vi &qu = queries[i];
        if(qu[0] == 2){
            int l = qu[1], r = qu[2];
            int mx = query(l, r);
            cout << ((mx < l) ? "YES"  : "NO") << '\n';
        }else{
            int k = qu[1], u = id(qu[2]);
            if(a[k] == u) continue;
            auto &s = pos[a[k]];
            auto it = s.find(k);
            int prev_pos = it == s.begin() ? 0 : *prev(it);
            auto nxt = next(it);
            if(nxt != s.end()){
                int nxt_pos = *nxt;
                change(nxt_pos, prev_pos);
            }
            s.erase(it);
            // new value
            a[k] = u;
            auto &u_s = pos[u];
            auto nxt_u = u_s.upper_bound(k);
            int u_prev_pos = (nxt_u == u_s.begin()) ? 0 : *prev(nxt_u);
            if(nxt_u != u_s.end()){
                int nxt_pos = *nxt_u;
                change(nxt_pos, k);
            }
            u_s.insert(k);
            change(k, u_prev_pos);
        }
    }
}

