#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<ll> vll;

#define pb push_back
#define endl '\n'
#define mid(x, y) (x) + ((y)-(x))/2
#define cinv(v) for(auto &i : v) {cin >> i;}

struct Vertex{
    Vertex *l, *r;
    ll sum;
    Vertex(int val) : l(nullptr), r(nullptr), sum(val) {}
    Vertex(Vertex *l, Vertex *r) :l(l), r(r), sum(0){
        if(l)sum+=l->sum;
        if(r)sum+=r->sum;
    }
};

Vertex* build(vll &a, int tl, int tr){
    if(tl==tr){
        return new Vertex(a[tl]);
    }
    int tm = mid(tl, tr);
    return new Vertex(build(a, tl, tm), build(a, tm+1, tr));
}

Vertex* update(Vertex *v,  int tl, int tr, int pos, ll val){
    if(tl==tr){
        return new Vertex(val);
    }
    int tm = mid(tl, tr);
    if(pos<=tm){
        return new Vertex(update(v->l, tl, tm, pos, val), v->r);
    }
    return new Vertex(v->l, update(v->r, tm+1, tr, pos, val));
}

ll query(Vertex* v,  int tl, int tr, int ql, int qr){
    if (ql > tr || qr < tl){
        return 0LL;
    }
    if(ql <= tl && tr <= qr){
        return v->sum;
    }
    int tm = mid(tl, tr);
    return query(v->l, tl, tm, ql, qr) + query(v->r, tm+1, tr, ql, qr);
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    
    int n, q; cin>>n>>q;
    vll arr(n); cinv(arr);

    vector<Vertex*> roots;
    roots.pb(build(arr, 0, n-1));    
    
    while(q--){
        int t; cin>>t;
        if(t==1){
            ll k, a, x; cin>>k>>a>>x;
            roots[k-1] = update(roots[k-1], 0, n-1, a-1, x);
        }
        if(t==2){
            ll k, a, b; cin>>k>>a>>b;
            cout << query(roots[k-1], 0, n-1, a-1, b-1) << endl;
        }
        if(t==3){
            ll k; cin>>k;
            roots.push_back(roots[k-1]);
        }
    }

    
}
