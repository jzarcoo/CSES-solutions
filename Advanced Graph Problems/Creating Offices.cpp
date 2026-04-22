#include<bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> ii;
typedef vector<ii> vii;
#define F first
#define endl '\n'
#define S second
#define pb push_back
#define rz assign
#define FOR(i,a,b) for(int i=a; i<b; i++)
#define sz(z)(int )z.size()
#define rall(v) v.rbegin(), v.rend()

const int N=2e5+5;
const int INF = INT_MAX;
const int INFM = INT_MIN;

int n, d, root = 1;
vi g[N], ans;
int nearest_office[N];
ii deep_candidate[N];

void dfs(int v, int p){
    int nearest_off = INF;
    set<ii> s;
    s.insert({0, v});
    for(int c : g[v]){
        if(c == p) continue;
        dfs(c, v);
        if(nearest_office[c] != INF){
            nearest_off = min(nearest_off, nearest_office[c] + 1);
        }
        auto [dist, cand] = deep_candidate[c];
        if(dist != INFM){
            s.insert({dist + 1, cand});
        }
    }
    while(!s.empty() && s.begin()->F + nearest_off < d){
        s.erase(s.begin());
    }
    while(sz(s) >= 2){
        auto it = s.rbegin();
        auto [d1, c1] = *it;
        auto [d2, _] = *next(s.rbegin());
        if(d1 + d2 < d){
            break;
        }
        ans.pb(c1);
        s.erase(*s.rbegin());
        nearest_off = min(nearest_off, d1);
        while(!s.empty() && s.begin()->F + nearest_off < d){
            s.erase(s.begin());
        }
    }
    nearest_office[v] = nearest_off;
    if(s.empty()){
        deep_candidate[v] = {INFM, -1};
    } else {
        deep_candidate[v] = *s.rbegin();
    }
    if(v == root && deep_candidate[v].F != INFM){
        ans.pb(deep_candidate[v].S);
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>d;
    FOR(i,1,n){
        int a, b; cin>>a>>b;
        g[a].pb(b);
        g[b].pb(a);
    }
    if(d==1){
        cout << n<<endl;
        FOR(v,1,n+1){
            cout<<v<<" ";
        }
        cout<<endl;
        return 0;
    }
    if(d==n){
        cout << 1 <<endl;
        cout << 1 <<endl;
        return 0;
    }
    
    dfs(root, 0);
    
    cout << sz(ans) << endl;
    for(int x:ans)cout<<x<<' ';
    cout<<endl;
}
