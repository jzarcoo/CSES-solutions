#include<bits/stdc++.h>
using namespace std;
const int N = 1e3+1;
int a[N];
int n, x;
bool solve(){
    map<int, pair<int,int>> m;
    for(int i=1; i<=n; i++){
        for(int j=i+1; j<=n; j++){
            if(m.count(x-a[i]-a[j])){
                cout << i <<' ' << j <<' ' << m[x-a[i]-a[j]].first <<' ' << m[x-a[i]-a[j]].second << '\n';
                return 1;
            }
        }
        for(int j=1; j<i; j++){
            m[a[i]+a[j]] = {i, j};
        }
    }
    return 0;
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin>>n>>x;
    for(int i=1; i<=n; i++){
        cin>>a[i];
    }
    if(!solve()){
        cout << "IMPOSSIBLE\n";
    }
    
}
