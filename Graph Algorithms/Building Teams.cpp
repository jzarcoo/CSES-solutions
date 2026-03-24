#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vll;
typedef vector<vll> vvll;
#define fori(i,a,b) for(int i=a; i<b;i++)
#define pb push_back
#define all(a) a.begin(), a.end()
const ll INF = LLONG_MAX;
void solve(){
    ll n, m; cin>>n>>m;
    vvll adj(n);
    fori(i,0,m){
        ll x, y; cin>>x>>y;
        adj[x-1].pb(y-1);
        adj[y-1].pb(x-1);
    }
    queue<ll> q;
    vector<int> color(n,-1);
    vector<bool> vis(n,false);
    fori(i,0,n){
        if (vis[i]) continue;
        color[i]=0;
        vis[i]=true;
        q.push(i);
        while(!q.empty()){
            ll cur = q.front();q.pop();
            for (ll vec : adj[cur]){
                if (color[vec]==-1){
                    vis[vec]=true;
                    color[vec] = 1 ^ color[cur];
                    q.push(vec);
                }else{
                    if (color[vec]==color[cur]){
                        cout<<"IMPOSSIBLE\n";
                        return;
                    }
                }
            }
        }
    }
    for(int &c : color) cout<<c+1<<' ';
    cout<<'\n';
}
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    solve();
    return 0;
}