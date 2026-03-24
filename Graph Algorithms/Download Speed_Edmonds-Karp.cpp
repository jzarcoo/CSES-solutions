// Time Complexity: VE^2
#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using pll=pair<ll,ll>;
using vll=vector<ll>;
using vvll = vector<vll>;
#define fori(i,a,b) for(int i=a;i<b;i++)
#define pb push_back
const ll INF=LLONG_MAX;
#define all(a) a.begin(), a.end()
ll n,m;
vvll adj, capacity;
ll bfs(ll s, ll t, vll & parent){
    fill(all(parent), -1);
    parent[s]=-2;
    queue<pll> q;
    q.push({s, INF});
    while (!q.empty()){
        auto [cur, flow] = q.front(); q.pop();
        for(ll next : adj[cur]){
            if (parent[next]==-1 && capacity[cur][next]){
                parent[next]=cur;
                ll new_flow = min(flow, capacity[cur][next]);
                if (next==t) return new_flow;
                q.push({next, new_flow});
            }
        }
    }
    return 0;
}
ll max_flow(ll s, ll t){
    ll max_flow=0; vll parent(n);
    while(ll new_flow=bfs(s,t,parent)){
        max_flow+= new_flow;
        ll cur = t;
        while(cur != s){
            ll prev = parent[cur];
            capacity[prev][cur]-= new_flow;
            capacity[cur][prev]+= new_flow;
            cur=prev;
        }
    }
    return max_flow;
}
int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    cin>>n>>m;
    adj.resize(n);
    capacity.assign(n, vll(n));
    fori(i,0,m){
        ll a, b, c; cin>>a>>b>>c;
        --a,--b;
        adj[a].pb(b);
        adj[b].pb(a);
        capacity[a][b] += c;
    }
    cout<<max_flow(0, n-1)<<'\n';
    return 0;
}