#include<bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n; cin>>n;
    vector<int> prufer(n-2), deg(n+1, 1);
    for(int i=0; i<n-2; i++){
        cin>>prufer[i];
        deg[prufer[i]]++;
    }
    set<int> leaves;
    for(int v=1; v<=n; v++){
        if(deg[v]==1){
            leaves.insert(v);
        }
    }
    for(int v : prufer){
        int mn_leaf = *leaves.begin();
        leaves.erase(leaves.begin());
        cout << mn_leaf << ' '<<v<<'\n';
        if(--deg[v]==1) leaves.insert(v);
    }
    cout << *leaves.begin() << ' '<<n<<'\n';
}
