#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pii;
const ll INF=LLONG_MAX;
struct Edge {
    ll a, b, cost;
    Edge(ll a, ll b, ll c){
        this->a = a;
        this->b = b;
        this->cost = c;
    }
};
void solve(){
    ll n,m;
    cin>>n>>m;
    vector<ll> d(n,0);
    vector<ll> p(n,-1);
    vector<Edge> edges;
    for(int i=0;i<m;i++){
        ll a,b,c;cin>>a>>b>>c;
        edges.push_back(Edge(a-1,b-1,c));
    }
    ll x=-1;
    for (int i = 0; i < n; ++i) {
        x = -1;
        for (Edge e : edges) {
            if (d[e.a] < INF) {
                if (d[e.b] > d[e.a] + e.cost) {
                    d[e.b] = max(-INF, d[e.a] + e.cost);
                    p[e.b] = e.a;
                    x = e.b;
                }
            }
        }
    }
    if (x == -1) {
        cout << "NO\n";
    } else {
        for (ll i = 0; i < n; ++i)
            x = p[x];
        vector<ll> cycle;
        for (ll v = x;; v = p[v]) {
            cycle.push_back(v);
            if (v == x && cycle.size() > 1)
                break;
        }
        reverse(cycle.begin(), cycle.end());
        cout<<"YES\n";
        for (int i = 0; i < cycle.size(); i++){
            cout << cycle[i]+1 << ' ';
        }
        cout << endl;
    }
}
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    solve();
    return 0;
}