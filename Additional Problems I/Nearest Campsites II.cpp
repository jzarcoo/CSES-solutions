#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = LLONG_MAX;
const ll INFM = LLONG_MIN;
const ll N = 1e6+5;
ll ft[N+1];
void add(int p, ll d){
    for(++p; p<=N; p += p & -p){
        ft[p] = max(d, ft[p]);
    }
}
ll query(ll p){
    ll s = INFM;
    for(++p; p; p -= p & -p){
        s = max(s, ft[p]);
    }
    return s;
}
struct Point{
    ll x, y;
    int i;
    bool operator<(const Point &p) const{
        return x < p.x;
    }
};
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n, m; cin>>n>>m;
    vector<Point> reserved(n), free(m);
    for(int i=0; i<n; i++){
        cin>>reserved[i].x>>reserved[i].y;
        reserved[i].i=i;
    }
    for(int i=0; i<m; i++){
        cin>>free[i].x>>free[i].y;
        free[i].i=i;
    }
    vector<ll> nearest_reserved(m, INF);
    auto solve = [&](){
        fill(ft, ft+N+1, INFM);
        sort(reserved.begin(), reserved.end());
        sort(free.begin(), free.end());
        int r=0;
        for(int i=0; i<m; i++){
            while(r<n && reserved[r].x<=free[i].x) {
                add(reserved[r].y, reserved[r].x + reserved[r].y);
                r++;                
            }
            ll q = query(free[i].y);
            if (q != INFM)
                nearest_reserved[free[i].i] = min(nearest_reserved[free[i].i],
                                                  free[i].x + free[i].y - q);
        }
    };
    for(int i=0; i<4; i++){
        solve();
        for(int r=0; r<n; r++){
            reserved[r].x = N - reserved[r].x;
            if(i==1){
                reserved[r].y = N - reserved[r].y;
            }
        }
        for(int f=0; f<m; f++){
            free[f].x = N - free[f].x;
            if(i==1){
                free[f].y = N - free[f].y;
            }
        }
    }
    for(int f=0; f<m; f++){
        cout << nearest_reserved[f]<< ' ';
    }
    
}
