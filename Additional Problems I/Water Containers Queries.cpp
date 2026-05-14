#include<bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    
    int n; cin>>n;
    while(n--){
        int a,b,x;
        cin>>a>>b>>x;
        if(x<=a && x%gcd(a,b)==0){
            cout << "YES\n";
        }else{
            cout <<"NO\n";
        }
    }
}
