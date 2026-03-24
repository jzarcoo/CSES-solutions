#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
struct node{
    ll sum, pref, suf, ans;
};
node make_data(ll v){
    ll m = max(0LL, v);
    return node{v,m,m,m};
}
struct seg{
    vector<node> st;
    int n;
    seg(vector<int> v) : n((int) v.size()) {
        st.resize(2*n);
        build(v,0,0,n-1);
    }
    node comb(node l, node r){
        node a;
        a.sum = l.sum+r.sum;
        a.pref = max(l.pref, l.sum+r.pref);
        a.suf = max(r.suf, l.suf+r.sum);
        a.ans = max({l.ans, r.ans, l.suf+r.pref});
        return a;
    }
    void build(vector<int> &a, int v, int tl, int tr){
        if(tl==tr){
            st[v]=make_data(a[tl]);
            return;
        }
        int tm = tl + (tr-tl)/2, l=v+1, r = v+2*(tm-tl+1);
        build(a, l, tl, tm);
        build(a, r, tm+1, tr);
        st[v] = comb(st[l], st[r]);
    }
    void upd(int v, int tl, int tr, int k, ll val){
        if(tl==tr){
            st[v]=make_data(val);
            return;
        }
        int tm = tl + (tr-tl)/2, l=v+1, r = v+2*(tm-tl+1);
        if(k<=tm){
            upd(l, tl, tm, k, val);
        }else{
            upd(r, tm+1, tr, k, val);
        }
        st[v] = comb(st[l], st[r]);
    }
    node query(int v, int tl, int tr, int ql, int qr){
        if (ql <= tl && tr <= qr){
            return st[v];
        }
        if (ql > tr || qr < tl){
            return make_data(0);
        }
        int tm = tl + (tr-tl)/2, l=v+1, r = v+2*(tm-tl+1);
        return comb(query(l,tl,tm,ql,qr),
                    query(r,tm+1,tr,ql,qr));
    }
};
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n, q; cin>>n>>q;
    vector<int> v(n); for(auto &i:v) cin>>i;
    seg t(v);
    while(q--){
        int a,b; cin>>a>>b;
        //t.upd(0,0,n-1,a-1,b);
        cout << t.query(0,0,n-1,a-1,b-1).ans <<endl;
    }
    return 0;
}
