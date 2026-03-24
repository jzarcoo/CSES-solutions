#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using vll = vector<ll>;
#define rz resize
#define eb emplace_back 
vector<vll> adj;
vll values, bit;
ll n,q;
vll tin,tout;
ll timer=0;
void add(ll i, ll delta){
    for(++i; i<= n; i += i & -i){
        bit[i] += delta;
    }
}
ll query(ll i){
    ll s=0;
    for(; i>=1; i -= i & - i){
        s += bit[i];
    }
    return s;
}
void euler_tour(ll at, ll prev=-1){
    tin[at]=timer;
    add(timer, values[at]);
    timer++;
    for(ll v:adj[at]){
        if (v==prev) continue;
        euler_tour(v, at);
    }
    tout[at]=timer;
}
int main(){
    ios_base::sync_with_stdio(false);cin.tie(nullptr);
    cin>>n>>q;
    values.rz(n), adj.rz(n), bit.rz(n+2), tin.rz(n), tout.rz(n);
    for(ll &i: values) cin>>i;
    for(int i=0;i<n-1;i++){
        ll a, b; cin>>a>>b; --a, --b;
        adj[a].eb(b);
        adj[b].eb(a);
    }
    euler_tour(0);
    while (q--){
        int op; cin>>op;
        ll node; cin>>node; --node;
        if (op==1) {
            ll new_val; cin>>new_val;
            ll delta = new_val - values[node];
            values[node] = new_val;
            add(tin[node], delta);
        }else{
            cout << query(tout[node]) - query(tin[node]) << '\n';
        }
    }
    return 0;
}