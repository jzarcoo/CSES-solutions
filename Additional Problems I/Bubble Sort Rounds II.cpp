#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    
    int n, k; cin>>n>>k;
    k = min(n-1, k);

    priority_queue<ll,vector<ll>, greater<ll>> pq;

    vector<ll> a(n);

    for(int i=0; i<n; i++){
        cin>>a[i];
        if(pq.size() <= k){
            pq.push(a[i]);
        }
    }

    for(int i=0; i<n; i++){
        cout <<  pq.top() << ' '; 
        pq.pop();
        if(i+k+1<n){
            pq.push(a[i+k+1]);
        }
    }

    cout <<'\n';
    
}
