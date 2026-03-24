#include<bits/stdc++.h>
using namespace std;
using ll=long long;
#define fori(i,a,b) for(int i=a; i<b;i++)
#define sz(a) (int)a.size()
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    string s; cin>>s;
    ll ans=1, tmp=1;
    char prev=s[0];
    fori(i,1,sz(s)){
        if (s[i]==prev){
            tmp++;
            ans=max(ans,tmp);
        }else{
            prev=s[i];
            tmp=1;
        }
    }
    cout<<ans<<'\n';
    return 0;
}