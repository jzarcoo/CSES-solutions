#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef complex<ll> point;
#define x real
#define y imag
#define sz(z) (int)z.size()

bool check(point p1, point p2, point p3){
    return (__int128) (p1.x()-p3.x()) * (p2.y() - p1.y()) >= (__int128) (p3.y()-p1.y()) * (p1.x()-p2.x());
}

ll get(point p, int i){
    return p.x() * i + p.y();
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    ll n, m; cin>>n>>m;
    vector<point> lines;
    for(int i=0; i<n; i++){
        ll y1, y2; cin>>y1>>y2;
        point p = {(y2-y1)/m, y1};
        lines.push_back(p);
    }
    sort(lines.begin(), lines.end(), [&](const point &a, const point &b){
        if(a.x() != b.x()) return a.x() < b.x();
        return a.y() > b.y();
    });
    vector<point> hull;
    for(int i = 0; i<n; i++){
        point cur = lines[i];
        if(!hull.empty() && hull.back().x() == cur.x()){
            continue;
        }
        while(sz(hull)>=2 && check(hull[sz(hull)-2], hull.back(), cur)){
            hull.pop_back();
        }
        hull.push_back(cur);
    }
    int p=0;
    for(int i=0; i<=m; i++){
        while(p+1<n && get(hull[p], i) <= get(hull[p+1], i)){
            p++;
        }
        cout << get(hull[p], i) << ' ';
    }
    
    
}
