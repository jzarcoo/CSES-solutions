#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
typedef vector<pll> vpll;
typedef vector<ll> vll;
#define fori(i,a,b) for(int i=a;i<b;i++)
ll N, M;
vll papa;
vll sizes;
vpll ans;
ll comp, largest;
ll find(ll n)
{
    return (papa[n]==n) ? n : papa[n] = find(papa[n]);
}
ll join(ll a, ll b)
{
    a = find(a), b= find(b);
    if (a==b) return -1;
    if (sizes[a] < sizes[b]) swap(a,b);
    sizes[a]+=sizes[b];
    papa[b]=a;
    return sizes[a];
}
int main()
{
ios_base::sync_with_stdio(0);cin.tie(0);
cin>>N>>M;
sizes.assign(N,1);
papa.resize(N);
fori(i,0,N){
    papa[i]=i;
}
comp=N; largest=1;
while(M--){
    ll a,b; cin>>a>>b;--a;--b;
    ll d = join(a,b);
    if(d!=-1){
        largest=max(largest, d);
        ans.push_back({--comp, largest});
    }else{
        ans.push_back({comp, largest});
    }
}
for(pll p : ans){
    cout<<p.first<<' '<<p.second<<'\n';
}
return 0;
}