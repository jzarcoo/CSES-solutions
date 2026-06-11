#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

#define print(v) for(auto &x : v){cout <<x <<' ';}cout<<'\n'

const ll INF = LLONG_MAX;

int n, k;
vector<ll> a, prefix, dp_prev, dp;

ll cost(int i, int j){
    ll s = prefix[j] - prefix[i-1];
    return s * s;
}

void compute(int l, int r, int optl, int optr){
    if(l>r){
        return;
    }
    int m = l + (r-l) / 2;
    pair<ll, int> best = {INF, -1};
    for(int i=optl; i<=min(m, optr); i++){
        ll new_cost = (i ? dp_prev[i-1] : 0) + cost(i+1, m+1);
        pair<ll, int> new_pair = {new_cost, i};
        best = min(best, new_pair);
    }
    dp[m] = best.first;
    int opt = best.second;
    compute(l, m-1, optl, opt);
    compute(m+1, r, opt, optr);
}

void solve(){
    prefix.resize(n+1); partial_sum(begin(a), end(a), prefix.begin()+1);
    
    dp_prev.resize(n);
    dp.resize(n);

    for(int i=0; i<n; i++){
        dp_prev[i] = cost(1, i+1);
    }
    for(int i=1; i<k; i++){
        compute(0, n-1, 0, n-1);
        dp_prev= dp;
    }

    cout << dp_prev[n-1] << '\n';
    
    
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin>>n>>k;
    a.resize(n);
    for(auto &i: a) cin>>i;
    solve();    
}
