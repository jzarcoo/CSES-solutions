#include<bits/stdc++.h>
using namespace std;
using ll=long long;
#define sz(a) (int)a.size()
#define fori(i,a,b) for(int i=a; i<b;i++)
const int MX=1e6+2;
ll criba[MX];
void build(){
    fori(i,0,MX) criba[i]=i;
    for(ll i=2;i*i<=MX;i++){
        if(criba[i]==i){
            for(ll j=i*i;j<=MX;j+=i){
                if (criba[j]==j){
                    criba[j]=i;
                }
            }
        }
    }
}
void solve(){
    ll n;cin>>n;
    ll ans=1;
    while(n>1){
        ll p = criba[n];
        ll c=1;
        while(n%p==0){
            c++;
            n/=p;
        }
        ans*=c;
    }
    cout<<ans<<'\n';
}
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int t; cin>>t;
    build();
    while(t--) solve();
    return 0;
}