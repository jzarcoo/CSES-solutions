#include<bits/stdc++.h>
using namespace std;
using ll=long long;
#define fori(i,a,b) for(int i=a; i<b;i++)
#define sz(a) (int)a.size()
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int n;cin>>n;
    ll ans=0;
    ll prev, curr; cin>>prev;
    while(cin>>curr){
        if (curr < prev){
            ans += prev - curr;
        }
        prev = max(prev, curr);
    }
    cout<<ans<<'\n';
    return 0;
}