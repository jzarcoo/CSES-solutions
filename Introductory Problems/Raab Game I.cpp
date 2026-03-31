#include<bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int t;cin>>t;
    while(t--){
        int n,a,b; cin>>n>>a>>b;
        if(a+b>n){
            cout<<"NO\n";
            continue;
        }
        if(a==b && a==0){
            cout<<"YES\n";
            for(int i=1; i<=n; i++){
                cout<<i<<' ';
            }
            cout<<'\n';
            for(int i=1; i<=n; i++){
                cout<<i<<' ';
            }
            cout<<'\n';
            continue;
        }
        if(a == a+b || b==a+b){
            cout<<"NO\n";
            continue;
        }
        cout<<"YES\n";
        for(int i=1; i<=n; ++i){
            cout<<i<<' ';
        }
        cout<<'\n';
        for(int i=1; i<=a+b; ++i){
            int x = i+a;
            if(x>a+b)x-=a+b;
            cout << x << ' ';
        }
        for(int i=a+b+1; i<=n; i++){
            cout<<i<<' ';
        }
        cout<<'\n';
        
    }
}
