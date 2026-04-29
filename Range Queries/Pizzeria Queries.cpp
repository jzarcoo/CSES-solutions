#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
struct seg{
    vector<ll> st;
    int n;
    ll NEUTER = 1e9;
    seg(int l){
        st.assign(4*l, NEUTER);
    }
    void upd(int v, int tl, int tr, int k, ll val){
        if(tl==tr){
            st[v] = val;
            return;
        }
        int tm = tl + (tr-tl)/2;
        if(k <= tm){
            upd(2*v, tl, tm, k, val);
        }else{
            upd(2*v+1, tm+1, tr, k, val);
        }
        st[v] = min(st[2*v], st[2*v+1]);
    }
    ll query(int v, int tl, int tr, int ql, int qr){
        if(tl > qr || tr < ql) return NEUTER;
        if(ql <= tl && tr <= qr){
            return st[v];
        }
        int tm = tl + (tr-tl)/2;
        return min(query(2*v, tl, tm, ql, qr),
                   query(2*v+1, tm+1, tr, ql, qr));
    }
};
int main(){
    int n, q;
    scanf("%d %d", &n, &q);
    seg b(n), f(n);
    auto upd = [&](int pos, ll price){
        b.upd(1, 0, n-1, pos-1, price - pos);
        f.upd(1, 0, n-1, pos-1, price + pos);
    };
    for(int i=1; i<=n; i++){
        ll price;
        scanf("%lli", &price);
        upd(i, price);
    }
    for(int _=0; _<q; _++){
        int t;
        scanf("%d", &t);
        if(t==1){
            int pos;
            ll new_price;
            scanf("%d %lli", &pos, &new_price);
            upd(pos, new_price);
        }else{
            int pos;
            scanf("%d", &pos);
            ll bmini = b.query(1, 0, n-1, 0, pos-1) + pos;
            ll fmini = f.query(1, 0, n-1, pos, n-1) - pos;
            ll res = min(bmini, fmini);
            //printf("%lli %lli ", bmini, fmini);
            printf("%lli\n", res);
        }
    }
}
