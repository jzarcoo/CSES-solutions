#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef struct node* pnode;
struct node{
    ll val, sum;
    bool rev;
    int prior;
    int cnt = 1;
    pnode l, r;
    node(ll v) : val(v),
                 prior(rand()),
                 l(NULL),
                 r(NULL)
    {}
} *treap;

int cnt(pnode t){
    return t ? t->cnt : 0;
}

ll sum(pnode t){
    return t ? t->sum : 0;
}

void upd(pnode t){
    if(!t){
        return;
    }
    t->cnt = 1 + cnt(t->l) + cnt(t->r);
    t->sum = t->val + sum(t->l) + sum(t->r);
}

void push(pnode t){
    if(!t){
        return;
    }
    if(t->rev){
        t->rev = 0;
        swap(t->l, t->r);
        if(t->l){
            t->l->rev ^= 1;
        }
        if(t->r){
            t->r->rev ^= 1;
        }
    }
}

void merge(pnode &t, pnode l, pnode r){
    push(l);
    push(r);
    if(!l || !r){
        t = l ? l  : r;
    }else if(l->prior > r->prior){
        merge(l->r, l->r, r);
        t = l;
    }else{
        merge(r->l, l, r->l);
        t = r;
    }
    upd(t);
}

void split(pnode t, int p, pnode &l, pnode &r){
    if(!t){
        l = r = NULL;
        return;
    }
    push(t);
    if(p <= cnt(t->l)){
        split(t->l, p, l, t->l);
        r = t;
    }else{
        split(t->r, p - 1 - cnt(t->l), t->r, r);
        l = t;
    }
    upd(t);
}

ll range_query(pnode &t, int l, int r){
    pnode t1,t2,t3;
    split(t, l-1, t1, t2);
    split(t2, r-l+1, t2, t3);
    ll ans = sum(t2);
    merge(t, t1, t2);
    merge(t, t, t3);
    return ans;
}

void reverse(pnode &t, int l, int r){
    pnode t1,t2,t3;
    split(t, l-1, t1, t2);
    split(t2, r-l+1, t2, t3);
    t2->rev= 1;
    merge(t, t1, t2);
    merge(t, t, t3);
}

int n, q;
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin>>n>>q;
    
    for(int i=0; i<n; i++){
        int x; cin>>x;
        merge(treap, treap, new node(x));
    }
    
    while(q--){
        int t, l, r; cin>>t>>l>>r;
        if(t==1){
            reverse(treap, l, r);
        }else{
            ll res = range_query(treap, l, r);
            cout << res <<'\n';
        }
    }
    
}
