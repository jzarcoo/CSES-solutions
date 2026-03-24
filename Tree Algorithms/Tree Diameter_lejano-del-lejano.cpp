#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vll;
typedef vector<vll> vvll;
#define fori(i,a,b) for(int i=a;i<b; i++)
#define pb push_back
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    ll n; cin>>n;
    vvll adj(n,vll());
    fori(i,1,n){
        ll a,b; cin>>a>>b;
        adj[a-1].pb(b-1);
        adj[b-1].pb(a-1);
    }
    vll dis(n);
    vector<bool> used(n);
    queue<ll> q;
    q.push(0);
    dis[0]=0;
    used[0]=true;
    while(!q.empty()){
        ll curr=q.front();q.pop();
        for(ll u: adj[curr]){
            if (used[u]) continue;
            q.push(u);
            dis[u]=dis[curr]+1;
            used[u] = true;
        }
    }
    ll mx=0;
    fori(i,1,n){
        if (dis[mx]<=dis[i]) mx=i;
    }
    dis.assign(n,0);
    used.assign(n,false);
    dis[mx]=0;
    q.push(mx);
    used[mx]=true;
    while(!q.empty()){
        ll curr=q.front();q.pop();
        for(ll u: adj[curr]){
            if (used[u]) continue;
            q.push(u);
            dis[u]=dis[curr]+1;
            used[u] = true;
        }
    }
    mx=0;
    fori(i,1,n){
        if (dis[mx]<=dis[i]) mx=i;
    }
    cout << dis[mx]<<endl;
    return 0;
}