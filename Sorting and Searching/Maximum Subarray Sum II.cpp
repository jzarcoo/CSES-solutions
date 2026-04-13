#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n;  cin>>n;
    int a, b; cin>>a>>b;
    vector<ll> v(n); for(auto &i:v) cin>>i;
    vector<ll> p(n+1,0); partial_sum(v.begin(), v.end(), p.begin()+1);
    ll ans = LLONG_MIN;
    deque<pair<ll, int>> dq;
    for(int r=a; r<=n; r++){
        while(!dq.empty()
              && dq.back().first >= p[r-a]){
            dq.pop_back();
        }
        dq.emplace_back(p[r-a], r-a);   
        if(dq.front().second < r - b) {
            dq.pop_front();
        }
        ans = max(ans, p[r] - dq.front().first); 
    }
    cout << ans <<'\n';
}
