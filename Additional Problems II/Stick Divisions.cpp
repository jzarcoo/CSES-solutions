#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2e5+5;
ll a[N];
ll n, x;

priority_queue<ll, vector<ll>, greater<ll>> pq;

ll solve(){
    if(n==1) return 0;
    ll cost = 0;
    while(pq.size() >= 2){
        ll fi = pq.top(); pq.pop();
        ll se = pq.top(); pq.pop();
        ll sum = fi+se;
        cost += sum;
        pq.push(sum);
    }
    return cost;
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin>>x>>n;
    for(int i=1; i<=n; i++){
        cin>>a[i];
        pq.push(a[i]);
    }
    cout << solve() << '\n';
}
