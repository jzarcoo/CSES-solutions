#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int POT = 1<<20;

void fwht(vector<ll> &v){
    int n = (int)v.size();
    for(int len = 1; len < n; len<<=1){
        for(int ini = 0; ini < n; ini += len << 1){
            for(int i=0; i<len; i++){
                ll a = v[ini + i], b = v[ini+i+len];
                v[ini+i] = a+b, v[ini+i+len] = a-b;
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n; cin>>n;
    vector<int> v(n); for(auto &i:v)cin>>i;

    vector<ll> prefix(POT);
    prefix[0] = 1;
    ll p = 0;
    bool zero = false;
    for(int i=0; i<n; i++){
        p^=v[i];
        if(++prefix[p] > 1) zero=true;
    }

    fwht(prefix);
    for(int i=0; i<POT; i++){
        prefix[i] *= prefix[i];
    }
    fwht(prefix);

    vector<int> r;
    if(zero)r.push_back(0);
    for(int i=1; i<POT; i++){
        if(prefix[i]>0) r.push_back(i);
    }
    
    int ans = (int)r.size();
    cout << ans << '\n';
    for(int i=0; i<ans; i++){
        cout << r[i] << " \n"[i==ans-1];
    }
}


