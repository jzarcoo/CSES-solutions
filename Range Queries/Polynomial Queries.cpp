#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define mid(l, r) (l) +((r)-(l))/2
const int N = 2e5+5;
struct node{
    ll sum=0, z0=0, z1=0;
    bool lazy=false;
    node() {}
};
node tree[4*N];
int n, q;
ll a[N];
node comb(const node &a, const node &b){
    node c;
    c.sum = a.sum + b.sum;
    return c;
}
void update(int v, int tl, int tr, int k, ll val){
    if(tl==tr){
        tree[v].sum = val;
        return;
    }
    int tm = mid(tl,tr);
    if(k<=tm){
        update(2*v, tl, tm, k, val);
    }else{
        update(2*v+1, tm+1, tr, k, val);
    }
    tree[v] = comb(tree[2*v], tree[2*v+1]);
}
void apply(int v, int tl, int tr, ll z0, ll z1){
    tree[v].sum += 1LL * (tr-tl+1) * z0;
    tree[v].sum += 1LL * (tr-tl) * (tr-tl+1) / 2 * z1;
    tree[v].z0 += z0;
    tree[v].z1 += z1;
    tree[v].lazy = true;
}
void push_down(int v, int tl, int tr){
    if(!tree[v].lazy) return;
    int tm = mid(tl,tr);
    
    apply(2*v, tl, tm, tree[v].z0, tree[v].z1);
    //
    ll r_z0 = tree[v].z0 + tree[v].z1 * (tm-tl+1);
    apply(2*v+1, tm+1, tr, r_z0, tree[v].z1);

    tree[v].lazy = false;
    tree[v].z0 = 0;
    tree[v].z1 = 0;
}
void range_update(int v, int tl, int tr, int ql, int qr, ll z0, ll z1){
    if(tl > qr || tr < ql) return;
    if(ql <= tl && tr <= qr){
        // 
        ll cur_z0 = z0 + z1*(tl-ql);
        apply(v, tl, tr, cur_z0, z1);
        return;
    }
    int tm = mid(tl, tr);
    push_down(v, tl, tr);
    range_update(2*v, tl, tm, ql, qr, z0, z1);
    range_update(2*v+1, tm+1, tr, ql, qr, z0, z1);
    tree[v] = comb(tree[2*v], tree[2*v+1]);
}
ll query(int v, int tl, int tr, int ql, int qr){
    if(tl>qr || tr < ql){
        return 0;
    }
    if(ql <= tl && tr <=qr){
        return tree[v].sum;
    }
    int tm=mid(tl, tr);
    push_down(v, tl, tr);
    ll left = query(2*v, tl, tm, ql, qr);
    ll right = query(2*v+1, tm+1, tr, ql, qr);
    return left + right;
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin>>n>>q;
    for(int i=1; i<=n; i++){
        cin>>a[i];
        update(1, 1, n, i, a[i]);
    }
    for(int qi=0; qi<q; qi++){
        int t, l, r; cin>>t>>l>>r;
        if(t==1){ // polynomial
            range_update(1,1,n,l,r, 1, 1);
        }else{
            ll ans = query(1,1,n,l,r);
            cout << ans << '\n';
        }
    }
}    

