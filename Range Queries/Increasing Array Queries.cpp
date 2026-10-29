#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2e5+5;
#define mid(l, r) (l) + ((r) - (l))/2
int n, q;
int v[N];
ll p[N];
vector<pair<int, int>> qs[N];
ll ans[N];

ll tree[4*N], lazy[4*N];

void apply(int v, int len, ll val){
    tree[v] = len * val;
    lazy[v] = val;
}

void push_down(int v, int tl, int tr){
    if(lazy[v] == 0) return;
    int tm = mid(tl, tr);
    apply(2*v, tm-tl+1, lazy[v]);
    apply(2*v+1, tr-tm, lazy[v]);
    lazy[v] = 0;    
}

void update(int v, int tl, int tr, int ql, int qr, ll delta){
    if(tl > qr || tr < ql){
        return;
    }
    if(ql <= tl && tr <= qr){
        apply(v, tr-tl+1, delta);
        return;
    }
    int tm = mid(tl, tr);
    push_down(v, tl, tr);
    update(2*v, tl, tm, ql, qr, delta);
    update(2*v+1, tm+1, tr, ql, qr, delta);
    tree[v] = tree[2*v] + tree[2*v+1];
}

ll query(int v, int tl, int tr, int ql, int qr){
    if(tl > qr || tr < ql){
        return 0;
    }
    if(ql <= tl && tr <= qr){
        return tree[v];
    }
    int tm = mid(tl, tr);
    push_down(v, tl, tr);
    return query(2*v, tl, tm, ql, qr) + query(2*v+1, tm+1, tr, ql, qr);
}

void solve(){
    stack<int> st;
    for(int i=n; i>=1; i--){
        while(!st.empty() && v[st.top()] <= v[i]){
            st.pop();
        }
        int mayor = st.empty() ? n+1 : st.top();
        st.push(i);

        update(1, 1, n, i, mayor-1, v[i]);

        // left
        for(auto &[r, id] : qs[i]){
            ll sum_mx = query(1, 1, n, i, r);
            ll sum = p[r] - p[i-1];
            ans[id] = sum_mx - sum;
        }
    }
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin>>n>>q;
    for(int i=1; i<=n; i++){
        cin>>v[i];
        p[i] = v[i] + p[i-1];
    }
    for(int i=1; i<=q; i++){
        int l, r; cin>>l>>r;
        qs[l].push_back({r, i});
    }
    solve();
    for(int i=1; i<=q; i++){
        cout << ans[i] << '\n';
    }
}

