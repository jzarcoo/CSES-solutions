// Time Complexity: V^2 E
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
vvll adj, capacity, flow;
queue<ll> excess_vertices;
vll height, excess, seen;
void push(ll from, ll to ){
    ll d = min(excess[from], capacity[from][to]-flow[from][to]);
    flow[from][to] += d;
    flow[to][from] -= d;
    excess[from]-=d;
    excess[to]+=d;
    if (d && excess[to]==d){
        excess_vertices.push(to);
    }
}
void relabel(ll v){
    ll d =INF;
    fori(i,0,n){
        if (capacity[v][i] > flow[v][i]){
            d=min(d, height[i]);
        }
    }
    if (d<INF){
        height[v] = d+1;
    }
}
void discharge(ll v){
    while(excess[v]>0){
        if (seen[v]<n){
            ll next =seen[v];
            if (capacity[v][next]>flow[v][next] && height[v]>height[next]){
                push(v, next);
            }else{
                seen[v]++;
            }
        }else{
            relabel(v);
            seen[v]=0;
        }
    }
}
ll max_flow(ll s, ll t){
    height[s]=n;
    excess[s]=INF;
    fori(i,0,n){
        if (i != s) {
            push(s, i);
        }
    }

    while(!excess_vertices.empty()){
        ll cur = excess_vertices.front(); excess_vertices.pop();
        if (cur != s && cur != t){
            discharge(cur);
        }
    }

    ll max_flow=0;
    fori(i,0,n){
        max_flow += flow[i][t];
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

    height.resize(n);
    excess.resize(n);
    seen.resize(n);
    flow.assign(n, vll(n, 0));

    cout<<max_flow(0, n-1)<<'\n';
    return 0;
}