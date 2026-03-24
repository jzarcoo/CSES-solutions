#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vll;
#define sz(a) (int) a.size()
#define cinv(v) for(auto &i:v) cin>>i
#define fori(i,a,b) for(int i=a;i<b;i++)
#define endl '\n'
template <class T> class ST{
public:
    const T NEUTER =0;
    int len;
    vector<T> st;
    ST (const vector<T> & v): len(sz(v)){
        st = vll(4*len, NEUTER);
        build(v);
    }
    void build(const vector<T> & v){
        fori(i,0,len){
            if (i==0){
                update(i+1, v[i]);
            } else {
                update(i+1, v[i] - v[i-1]);
            }
        }
    }
    T merge (const T &a, const T &b){
        return a + b;
    }
    T query(int pos){
        return query(1, 0, len-1, 0, pos-1);
    }
    T query(int at, int tl, int tr, int l, int r){
        if (l <=tl && tr<=r){
            return st[at];
        }
        if (tr < l || tl > r){
            return NEUTER;
        }
        int tm = tl + (tr-tl)/2;
        return merge(
            query(at*2, tl, tm, l, r),
            query(at*2+1, tm+1, tr, l, r)
        );
    }
    void update(int pos, T val){
        update(1, 0, len-1, pos-1, val);
    }
    void update(int at, int tl, int tr, int pos, T val){
        if (tl == tr){
            st[at] += val;
            return;
        }
        int tm = tl + (tr-tl)/2;
        if (pos <= tm){
            update(at*2, tl, tm, pos, val);
        }else{
            update(at*2+1, tm+1, tr, pos, val);
        }
        st[at] = merge(st[at*2], st[at*2+1]);
    }

};
void solve(){
    int n, q; cin>>n>>q;
    vll a(n); cinv(a);
    ST st(a);
    while(q--){
        int o; cin>>o;
        if (o==1){
            int a,b,i; cin>>a>>b>>i;
            st.update(a,i);
            if (b != n)
                st.update(b+1,-i);
        }else{
            int pos; cin>>pos;
            cout<< st.query(pos) <<endl;
        }
    }
}
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    solve();
    return 0;
}