#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 1e6+5,
    INF = LLONG_MAX,
    INFM = LLONG_MIN;
ll ft[N+1];
void upd(int p, ll v){
    for(++p; p<=N; p+=p&-p)ft[p] = max(ft[p], v);
}
ll qu(int i){
    ll r = INFM;
    for(++i; i; i-= i&-i) r = max(r, ft[i]);
    return r;
}
struct P{
    ll x, y;
    int i;
    bool operator<(const P &p) const{
        return x<p.x;
    }
};
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n, m; cin>>n>>m;
    vector<P> re(n), fe(m), reserved, free;
    for(int i=0; i<n; i++){
        cin>>re[i].x>>re[i].y;
        re[i].i=i;
    }
    for(int i=0; i<m; i++){
        cin>>fe[i].x>>fe[i].y;
        fe[i].i=i;
    }
    reserved = re, free = fe;
    vector<ll> d(m, INF);
    /*
      xf >= xr && yf >= yr
      |-> (xf-xr) + (yf-yr)
          =  (xf+yf) - (xr+yr)
     */
    fill(ft, ft+N+1, INFM);
    int r=0;
    sort(reserved.begin(), reserved.end());
    sort(free.begin(), free.end());
    for(int i=0; i<m; i++){
        while(r<n && reserved[r].x<=free[i].x) {
            upd(reserved[r].y, reserved[r].x + reserved[r].y);
            r++;                
        }
        ll q = qu(free[i].y);
        if (q != INFM)
            d[free[i].i] = min(d[free[i].i],
                               free[i].x + free[i].y - q);
    }
    /*
      xf <= xr && yf <= yr
      |-> (xr-xf) + (yr-yf)
          =  (xr+yr) - (xf+yf)

          (-xf-yf) - (-xr-yr) 
     */
    fill(ft, ft+N+1, INFM);
    r=n-1;
    for(int f = m-1; f>=0; f--){
        while(r>=0 && reserved[r].x >= free[f].x){
            upd(N - reserved[r].y, - reserved[r].x - reserved[r].y);
            r--;
        }
        ll q = qu(N - free[f].y);
        if (q != INFM)
            d[free[f].i] = min(d[free[f].i],
                               - free[f].x - free[f].y - q);
    }
    /*
      xf <= xr && yf >= yr
      |-> (xr-xf) + (yf-yr)

      (yf-xf) - (yr-xr)
     */
    fill(ft, ft+N+1, INFM);
    r=n-1;
    for(int f = m-1; f>=0; f--){
        while(r>=0 && reserved[r].x >= free[f].x){
            upd(reserved[r].y, reserved[r].y - reserved[r].x);
            r--;
        }
        ll q = qu(free[f].y);
        if (q != INFM)
            d[free[f].i] = min(d[free[f].i],
                               free[f].y - free[f].x - q);
    }
    /*
      xf >= xr && yf <= yr
      |-> (xf-xr) + (yr-yf)

      (xf-yf) - (xr-yr)
     */
    fill(ft, ft+N+1, INFM);
    r=0;
    for(int i=0; i<m; i++){
        while(r<n && reserved[r].x<=free[i].x) {
            upd(N-reserved[r].y, reserved[r].x - reserved[r].y);
            r++;                
        }
        ll q = qu(N-free[i].y);
        if (q != INFM)
            d[free[i].i] = min(d[free[i].i],
                               free[i].x - free[i].y - q);
    }
    cout << *max_element(d.begin(), d.end());
}
