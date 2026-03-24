#include<bits/stdc++.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int n, k; cin>>n>>k;
    int ans=0;
    vector<pair<int,int>> v;
    while(n--){
        int s, e; cin>>s>>e;
        v.emplace_back(e,s);
    }
    sort(begin(v), end(v));
    multiset<int> ms;
    for(int i=0; i<k; i++){
        ms.insert(0);
    }
    for(auto &[e, s] : v){
        auto it = ms.upper_bound(s);
        if (it == ms.begin()) {
            continue;
        }
        --it;
        int disp = *it;
        ms.erase(it);
        ms.insert(e);
        ans++;
    }
    cout<<ans<<endl;
    return 0;
}

