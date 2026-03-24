#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vll;
#define cinv(v) for (auto &i:v) cin>>i;
#define sz(a) (int) a.size()
#define endl '\n'
template <class T> class ST{
public:
    vector<T> st;
    int len;
    const T NEUTER = 0;
    ST(int len) : len(len){
        st = vector<T> (4*len, NEUTER);
    }
    ST(const vector<T> & v) : len(sz(v)){
        st = vector<T>(4*len, NEUTER);
        build(v, 1, 0, len-1);
    }
    void build(const vector<T> &v, int at, int tl, int tr){
        if (tl==tr){
            st[at] = v[tl];
            return;
        }
        ll tm = tl + (tr-tl)/2;
        build(v, 2*at, tl, tm);
        build(v, 1+ 2*at, tm+1, tr);
        st[at] = merge(st[2*at], st[1+2*at]);
    }
    T merge(const T &a, const T &b){
        return a^b;
    }
    T query(int l, int r){
        return query(1, 0, len-1, l-1, r-1);
    }
    T query(int at, int tl, int tr, int l, int r){
        if (l <= tl && tr <= r){
            return st[at];
        }
        if (l > tr || tl > r){
            return NEUTER;
        }
        ll m = tl + (tr-tl)/2;
        return merge(
            query(at*2, tl, m, l, r),
            query(at*2 +1, m+1, tr, l, r)
        );
    }
};
void solve(){
    int n, q; cin>>n>>q;
    vll a(n);cinv(a);
    ST st(a);
    while(q--){
        int a,b;cin>>a>>b;
        cout<<st.query(a,b)<<endl;
    }
}
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    solve();
    return 0;
}