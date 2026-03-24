#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using vll= vector<ll>;
ll N, Q, LOG;
vector<vll> st;
int log2_floor(unsigned long long i) {
    return i ? __builtin_clzll(1) - __builtin_clzll(i) : -1;
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(nullptr);
    cin>>N>>Q;


    LOG = log2_floor(N);
    st.assign(N, vll(LOG+1));
    for(int i=0;i<N;i++){
        cin>> st[i][0];
    }
    for(int k=1; k<=LOG; k++){
        for(int i=0; i+(1<<k) <= N; i++){
            st[i][k] = min(st[i][k-1], st[i+(1<<(k-1))][k-1]);
        }
    }

    while(Q--){
        ll l, r; cin>>l>>r; --l,--r;
        ll k = log2_floor(r-l+1);
        cout<< min(st[l][k], st[r-(1<<k)+1][k]) << '\n';
    }


    return 0;
}