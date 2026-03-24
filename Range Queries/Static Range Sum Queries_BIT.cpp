#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using vll = vector<ll>;
#define fori(i,a,b) for(int i=a;i<b;i++)
ll N, Q;
vll bit, arr;
void update(ll i, ll val){
    arr[i]+=val;
    i++;
    while(i <= N){
        bit[i] += val;
        i += i & -i;
    }
}
ll query(ll i){
    i++;
    ll sum = 0;
    while(i > 0){
        sum += bit[i];
        i -= i & -i;
    }
    return sum;
}
int main(){
    ios_base::sync_with_stdio(false);cin.tie(nullptr);
    cin>>N>>Q;
    arr.resize(N);
    bit.resize(N+1); // 1-based
    fori(i,0,N){
        ll n; cin>>n;
        update(i, n);
    }
    while(Q--){
        ll a,b; cin>>a>>b;
        cout << query(b-1) - query(a-2) << endl;
    }
    return 0;
}