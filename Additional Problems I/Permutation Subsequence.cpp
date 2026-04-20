#include<bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n, m; cin>>n>>m;
    vector<int> a(n), b(m), atob, original;
    unordered_map<int,int> posb;
    for(int i=0; i<n; i++){
        cin>>a[i];
    }
    for(int i=0; i<m; i++){
        int x; cin>>x;
        b[i] = x;
        posb[x] = i;
    }
    for(int x : a){
        if(posb.count(x)){
            atob.push_back(posb[x]);
            original.push_back(x);
        }
    }
    vector<int> tail_pos, tail_value, parent(n, -1);
    for(int i=0; i<(int)atob.size(); i++){
        int x = atob[i];
        int pos = lower_bound(tail_value.begin(), tail_value.end(), x) - tail_value.begin();
        if(pos == (int) tail_value.size()){
            tail_pos.push_back(i);
            tail_value.push_back(x);
        }else{
            tail_pos[pos] = i;
            tail_value[pos] = x;
        }
        if(pos>0) parent[i] = tail_pos[pos-1];
    }
    int length = tail_pos.size();
    vector<int> lis(length);
    int idx = tail_pos.back();
    for(int i=length-1; i>=0; i--){
        lis[i] = idx;
        idx = parent[idx];
    }
    cout << length <<'\n';
    for(int x: lis) cout<<original[x]<<' ';
}
