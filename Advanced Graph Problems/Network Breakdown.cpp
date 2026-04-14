#include<bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n, m, k; cin>>n>>m>>k;
    vector<pair<int,int>> edges;
    set<pair<int,int>> removed;
    vector<pair<int,int>> queries(k);
    vector<int> e(n+1, -1), ans(k);
    int components = n;
    function<int(int)> get = [&](int x) -> int{
        return e[x] < 0 ? x : e[x] = get(e[x]);
    };
    auto join = [&](int a, int b) -> bool{
        a = get(a), b = get(b);
        if(a==b) return 0;
        if(e[a]>e[b]) swap(a,b);
        e[a] += e[b];
        e[b] = a;
        components--;
        return 1;
    };
    for(int i=0,a,b; i<m; i++){
        cin>>a>>b;
        if(a>b) swap(a,b);
        edges.emplace_back(a, b);
    }
    for(int i=0,a,b; i<k; i++){
        cin>>a>>b;
        if(a>b) swap(a,b);
        queries[i] = {a,b};
        removed.emplace(a,b);
    }
    for(auto &[a,b]: edges){
        if(removed.find({a,b}) == removed.end()){
            join(a, b);
        }
    }
    for(int i=k-1; i>=0; i--){
        ans[i] = components;
        join(queries[i].first, queries[i].second);
    }
    for(int x : ans) cout<<x<<' ';
}
