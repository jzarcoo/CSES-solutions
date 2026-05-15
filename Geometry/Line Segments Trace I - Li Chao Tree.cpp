#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef complex<ll> point;
#define x real
#define y imag
#define sz(z) (int)z.size()

vector<point> tree;

ll dot(point a, point b){
    return (conj(a)*b).x();
}

ll f(point a, ll x){
    return dot(a, {x, 1});
}

void add_line(point nw, int v, ll l, ll r){
    ll m = l + (r-l)/2;
    bool lef = f(nw, l) > f(tree[v], l);
    bool mid = f(nw, m) > f(tree[v], m);
    if(mid){
        swap(tree[v], nw);
    }
    if(r-l==1) return;
    if(lef != mid){
        add_line(nw, 2*v, l, m);
    }else{
        add_line(nw, 2*v+1, m, r);
    }
}

ll get(ll i, int v, ll l, ll r){
    ll m = l + (r-l)/2;
    if(r-l==1){
        return f(tree[v], i);
    }
    if(i<m){
        return max(f(tree[v], i), get(i, 2*v, l, m));
    }
    return max(f(tree[v], i), get(i, 2*v+1, m, r));
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    ll n, m; cin>>n>>m;
    tree.assign(4*m, point(0, (ll) -1e18));

    
    for(int i=0; i<n; i++){
        ll y1, y2; cin>>y1>>y2;
        point p = {(y2-y1)/m, y1};
        add_line(p, 1, 0, m);
    }
    
    for(int i=0; i<=m; i++){
        cout << get(i,1, 0,m) << ' ';
    }
    
    
}
