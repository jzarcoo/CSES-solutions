#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> ii;

#define endl '\n';
#define fi first
#define se second

const int N=1e3;
const ll INF = LLONG_MAX;

ll d[N+1][N+1];
string prev_move[N+1][N+1];
ii p[N+1][N+1];

bool ckmin(ll &a, ll b){
    return (b<a) ? a=b, 1 : 0;
}
struct Cell{
    ll d,  r,c;
    Cell(ll _d, ll _r, ll _c){
        d = _d;
        r = _r;
        c = _c;
    }
    bool operator<(const Cell &o) const{
        return d > o.d;
    }
};

ll a,b,x;

void dijkstra(){
    fill(&d[0][0], &d[0][0] + (N+1)*(N+1), INF);
    fill(&p[0][0], &p[0][0] + (N+1)*(N+1), make_pair(-1,-1));
    d[0][0] = 0;

    priority_queue<Cell> pq;
    pq.emplace(0,0,0);

    while(!pq.empty()){
        Cell cur = pq.top(); pq.pop();
        if(cur.d > d[cur.r][cur.c]) continue;

        auto check = [&](string s, ll new_a, ll new_b, ll m){
            if(ckmin(d[new_a][new_b], m + cur.d)){
                prev_move[new_a][new_b] = s;
                p[new_a][new_b] = make_pair(cur.r, cur.c);
                pq.emplace(d[new_a][new_b], new_a, new_b);
            }
        };
        
        check("FILL A", a, cur.c, a-cur.r);
        check("FILL B", cur.r, b, b-cur.c);
        check("EMPTY A", 0, cur.c, cur.r);
        check("EMPTY B", cur.r, 0, cur.c);
        ll m = min(cur.r, b-cur.c);
        check("MOVE A B", cur.r-m, cur.c+m, m);
        m = min(cur.c, a- cur.r);
        check("MOVE B A", cur.r+m, cur.c-m, m);
    }
}

void find_min(ll &col, ll &min_w){
    for(int i=0; i<=b; i++){
        if(ckmin(min_w, d[x][i])){
            col = i;
        }
    }
}

void solve(){
    dijkstra();
    // d[x][?] = ?
    ll col = -1, min_w = INF;
    find_min(col, min_w);

    // path
    ii cur = {x, col};
    vector<string> ans;
    while(cur != make_pair(0,0)){
        ans.push_back(prev_move[cur.fi][cur.se]);
        cur = p[cur.fi][cur.se];
    }
    reverse(ans.begin(), ans.end());

    cout << ans.size();
    cout << ' ';
    cout << min_w;
    cout << endl;

    for(auto &s: ans){
        cout << s << endl;
    }
}


int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin>>a>>b>>x;
    if(x<=a && x%gcd(a,b)==0){
        solve();
    }else{
        cout << "-1\n";
    }
}

