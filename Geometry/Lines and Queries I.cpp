#include<bits/stdc++.h>
using namespace std;
typedef long long ftype;
typedef complex<ftype> point;
#define x real
#define y imag
const int maxn = 1e5;
const point NEUTRAL = {0, (ftype)-1e18};
point line[4*maxn];
ftype dot(point a, point b){
    return (conj(a)*b).x();
}
ftype f(point a, ftype x){
    return dot(a, {x,1});
}
void add_line(point nw, int v=1, int l=0, int r=maxn){
    int m = l + (r-l)/2;
    bool lef = f(nw, l)>f(line[v], l),
        mid = f(nw, m) > f(line[v], m);
    if(mid) swap(line[v], nw);
    if(r-l==1) return;
    if(lef!=mid) add_line(nw, 2*v, l, m);
    else add_line(nw, 2*v+1, m, r);
}
ftype get(int x, int v=1, int l=0, int r=maxn){
    int m = l + (r-l)/2;
    if(r-l==1) return f(line[v], x);
    if(x<m) {
        return max(f(line[v], x), get(x, 2*v, l, m));
    }
    return max(f(line[v], x), get(x, 2*v+1, m, r));
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    fill(line, line  + 4*maxn, NEUTRAL);
    int n; cin>>n;
    while(n--){
        int t; cin>>t;
        if(t==1){
            ftype a, b; cin>>a>>b;
            point p = {a,b};
            add_line(p);
        }else{
            int pos; cin>>pos;
            cout << get(pos) << '\n';
        }
    }
}
