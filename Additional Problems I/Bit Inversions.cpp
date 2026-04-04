#include<bits/stdc++.h>
using namespace std;
string s;
int m, q;
struct node{
    int p1=0, s1=0, r1=0, p0=0, s0=0, r0=0, l=0;
    node () {}
    node(char c){
        l=1;
        if(c=='0'){
            p0=s0=r0=1;
        }else{
            p1=s1=r1=1;
        }
    }
};
struct seg{
    vector<node> st;
    int n;
    seg(string s){
        n = s.size();
        st.resize(2*n);
        build(s, 0, 0, n-1);
    }
    node comb(node a, node b){
        if(a.l==0) return b;
        if(b.l==0) return a;
        node c;
        c.l = a.l+b.l;
        c.p1 = a.p1 == a.l ? a.l + b.p1 : a.p1;
        c.p0 = a.p0 == a.l ? a.l + b.p0 : a.p0;
        c.s1 = b.s1 == b.l ? a.s1 + b.l : b.s1;
        c.s0 = b.s0 == b.l ? a.s0 + b.l : b.s0;
        c.r1 = max({a.r1, b.r1, a.s1+b.p1});
        c.r0 = max({a.r0, b.r0, a.s0+b.p0});
        return c;
    }
    void build(string &s, int v, int tl, int tr){
        if(tl==tr){
            st[v] = node(s[tl]);
            return;
        }
        int tm = tl + ((tr-tl)>>1), l=v+1, r = v+((tm-tl+1)<<1);
        build(s, l, tl, tm);
        build(s, r, tm+1, tr);
        st[v] = comb(st[l], st[r]);
    }
    void upd(int k, char val, int v, int tl, int tr){
        if(tl==tr){
            st[v] = node(val);
            return;
        }
        int tm = tl + ((tr-tl)>>1), l=v+1, r = v+((tm-tl+1)<<1);
        if(k<=tm) upd(k, val, l, tl, tm);
        else upd(k, val, r, tm+1, tr);
        st[v] = comb(st[l], st[r]);
    }
};
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin>>s>>m; 
    seg tree(s);
    while(m--){
        cin>>q; q--;
        s[q] = (s[q]=='0') ? '1' : '0';
        tree.upd(q, s[q], 0, 0, tree.n-1);
        node ans = tree.st[0];
        cout << max(ans.r1, ans.r0) << ' ';
    }
}
