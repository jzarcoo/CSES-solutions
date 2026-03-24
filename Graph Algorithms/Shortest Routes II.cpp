#include<bits/stdc++.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n,m,q; cin>>n>>m>>q;
    vector<vector<long long>> d(n,vector<long long>(n,LLONG_MAX));
    while(m--){
        int a,b,c;cin>>a>>b>>c;
        if (c < d[a-1][b-1]){
            d[a-1][b-1]=c;
            d[b-1][a-1]=c;
        }
    }
    for(int k=0;k<n;k++){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if (d[i][k] < LLONG_MAX && d[k][j] < LLONG_MAX){
                    d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
                }
            }
        }
    }
    while(q--){
        int a,b;cin>>a>>b;
        if (a==b)
            cout << 0<<endl;
        else if (d[a-1][b-1]==LLONG_MAX)
            cout << -1<<endl;
        else
            cout << d[a-1][b-1]<<endl;
    }

    return 0;
}