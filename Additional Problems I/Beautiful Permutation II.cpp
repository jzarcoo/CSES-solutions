#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
int n;
vector<int> ans;
set<int> nums;
bool rec(){
    if((int)ans.size()==n){
        return 1;
    }
    for(auto it = nums.begin(); it != nums.end();){
        int x = *it;
        it++;
        if(!ans.empty() && abs(ans.back() - x) == 1) continue;
        ans.push_back(x);
        nums.erase(x);
        if(rec()){
            return 1;
        }
        ans.pop_back();
        nums.insert(x);
    }
    return 0;
}
void solve(){
    for(int i=1; i<=n; i++){
        nums.insert(i);
    }
    rec();
    for(int x : ans){
        cout << x << ' ';
    }
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin>>n;
    if(n==1){
        cout << n << endl;
    }else if(n<4){
        cout << "NO SOLUTION" << endl;
    }else solve();
}
