#include<bits/stdc++.h>
using namespace std;
vector<string> dfs(int n){
    if(n==1){
        return {"0", "1"};
    }
    vector<string> prevv = dfs(n-1);
    vector<string> copyy(prevv.rbegin(), prevv.rend());
    for(auto &s:prevv){
        s+="0";
    }
    for(auto &s:copyy){
        s+="1";
    }
    prevv.insert(prevv.end(), copyy.begin(), copyy.end());
    return prevv;
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n; cin>>n;
    for(auto &s : dfs(n)) cout << s<<'\n';
}
