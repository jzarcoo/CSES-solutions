#include <bits/stdc++.h>
using namespace std;
#pragma GCC target("popcnt") 
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n, l = INT_MAX, r=0; cin>>n;
    unordered_map<int, int> v;
    for(int i=0, x; i<n;i++){
        cin>>x;
        v[x]++;
        l = min(l, x); r += x;
    }
    bitset<100001> can; can[0]=1;
    for(auto &[val, cnt] : v){
        int pot = 1;
        while(cnt > 0){
            int take = min(pot, cnt);
            can |= can << (take * val);
            cnt -= take;
            pot <<= 1;
        }
    }
    vector<int> a;
    for(int i=l; i<=r;i++)
        if(can[i]) 
            a.emplace_back(i);
    cout<<a.size()<<endl;
    for(int x: a)cout<<x<<' ';
}
