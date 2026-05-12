#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vll;
#define all(z) z.begin(),z.end()

ll n, q;

struct Query{
    int pos;
    ll c, d;
    int i;
    int type;
    bool operator<(const Query &o) const{
        return pos < o.pos;
    }
};

struct FT{
    vll bit;
    int n;
    FT(int _n){
        bit.assign(_n+1, 0);
        n = _n;
    }
    void add(int i, ll d){
        for(; i<=n; i+= i&-i)
            bit[i]+=d;
    }
    ll sum(int i){
        ll s=0;
        for(; i>0; i-= i&-i)
            s+=bit[i];
        return s;
    }
    ll sum(ll l, ll r){
        if(l>r)return 0;
        return sum(r) - sum(l-1);
    }
};

vll arr, ans, vals;
vector<Query> qu;
FT* tree;
int len;

void compress(){
    sort(all(vals));
    vals.erase(unique(all(vals)), vals.end());
    for(int i=0; i<n; i++){
        arr[i] = lower_bound(all(vals), arr[i]) - vals.begin()+1;
    }
    for(int i=0; i<2*q; i++){
        qu[i].c = lower_bound(all(vals), qu[i].c) - vals.begin()+1;
        qu[i].d = lower_bound(all(vals), qu[i].d) - vals.begin()+1;
    }    

    len = vals.size();
    tree = new FT(len);
}

void solve(){
    compress();
    
    sort(all(qu));

    int p=-1;
    for(const Query &qq : qu){
        while(qq.pos > p){
            tree->add(arr[++p], 1);
        }
        ans[qq.i] += qq.type *tree->sum(qq.c, qq.d);
    }
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin>>n>>q;
    arr.resize(n);

    for(int i=0; i<n; i++){
        cin>>arr[i];
        vals.push_back(arr[i]);
    }
    
    for(int i=0; i<q; i++){
        int a, b;
        ll c,d;
        cin>>a>>b>>c>>d;
        
        vals.push_back(c);
        vals.push_back(d);
        
        --a, --b; 
        
        qu.push_back(Query{a-1, c, d, i, -1});
        qu.push_back(Query{b, c, d, i, 1});
    }

    ans.assign(q, 0);
    solve();
    
    for(ll x: ans)cout<<x<<'\n';
}

