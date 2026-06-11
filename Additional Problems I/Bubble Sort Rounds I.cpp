#include<bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n; cin>>n;
    vector<pair<int,int>> a(n);
    for(int i=0; i<n; i++){
        cin>>a[i].first;
        a[i].second = i;
    }

    stable_sort(a.begin(), a.end());

    int ans = 0;
    for(int i=0; i<n; i++){
        ans = max(ans, a[i].second-i);
    }

    cout << ans << '\n';
    
}
