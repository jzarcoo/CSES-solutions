#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
typedef vector<ll> vll;
typedef vector<vll> vvll;
#define all(v) v.begin(), v.end()
#define rall(v)v.rbegin(), v.rend()
#define fori(i,a,n) for(ll i=a; i<n;i++)
#define sz(a) (int )a.size()
#define pb push_back
class DSU {
public:
    vll parent,sizes;
    DSU(int len):parent(len),sizes(len){
        fori(i,0,len){
            parent[i]=i;
        }
    }
    ll find(ll x){
        return (parent[x]==x)?x:parent[x]=find(parent[x]);
    }
    bool join(ll x, ll y){
        x=find(x), y=find(y);
        if (x==y) return false;
        if (sizes[x]<sizes[y]) swap(x,y);
        parent[y]=x;
        sizes[x]+=sizes[y];
        return true;
    }
    bool same(ll x, ll y){
        return find(x)==find(y);
    }
};
struct Road {
    ll from, to, cost;
};
void solve(){
    ll n, m; cin>>n>>m;
    vector<Road> r;
    fori(i,0,m){
        ll a,b,c; cin>>a>>b>>c;
        r.pb({a,b,c});
    }
    sort(all(r), [&](const Road &r1, const Road &r2){
        return r1.cost < r2.cost;
    });
    ll edges=0;
    ll mn = 0;
    DSU aux(n+1);
    for(Road & ro : r){
        bool c = aux.join(ro.from, ro.to);
        mn += c * ro.cost;
        edges += c;
    }
    if (edges != n-1){
        cout<<"IMPOSSIBLE"<<endl;
    } else {
        cout <<mn<<endl;
    }
}
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0); cout.tie(0);
    solve();
    return 0;
}