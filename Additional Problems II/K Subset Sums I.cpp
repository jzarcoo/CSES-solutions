#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vll;

#define cinv(z) for(auto &i: z )cin>>i
#define FOR(i,a,b) for(int i=a; i<b; i++)
#define rep(e, v) for(auto &e : v)
#define all(z)z.begin(), z.end()
#define fi first
#define se second

int n, k;
vll v;

void solve(){
    ll mini = 0;
    rep(e, v){
        if(e<0){
            mini += e;
            e = -e;
        }
    }
    sort(all(v));
    
    k--;
    cout << mini << ' '; 

    priority_queue<pair<ll, int>> pq;
    pq.push({-v[0], 0});

    while(k--){
        auto p = pq.top(); pq.pop();
        p.fi = -p.fi;
        cout << mini + p.fi << ' ';
        if(p.se+1 < n){
            pq.push({-(p.fi + v[p.se+1]), p.se+1});
            pq.push({-(p.fi - v[p.se] + v[p.se+1]), p.se+1});
        }
    }
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin>>n>>k;
    v = vll(n); 
    cinv(v);
    solve();
}
