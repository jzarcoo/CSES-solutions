#include <bits/stdc++.h>

#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef pair<int,int> ii;
typedef long long ll;

typedef tree<
ii, 
null_type,
less<ii>,
rb_tree_tag,
tree_order_statistics_node_update
> o_set;

#define mid(l,r) (l)  + ((r)-(l)) / 2

const int N = 2e5+5;

int n, k;
int in[N];

int med;

ll st[4*N];
o_set t;

unordered_map<int, int> original, compress;
int distinct;

void compression(){
    vector<int> vals(in+1, in+n+1);
    sort(vals.begin(), vals.end());
    vals.erase(unique(vals.begin(), vals.end()), vals.end());
    
    for(int i=1; i<=n; i++){
        int value = in[i];
        int idx = lower_bound(vals.begin(), vals.end(), value) - vals.begin() + 1;
        compress[value] = idx;
        original[idx] = value;
    }

    distinct = vals.size();
}

void update(int v, int tl, int tr, int pos, ll d){
    if(tl==tr){
        st[v] += d;
        return;
    }
    int tm = mid(tl,tr);
    if(pos<=tm){
        update(2*v, tl, tm, pos, d);
    }else{
        update(2*v+1, tm+1, tr, pos, d);
    }
    st[v] = st[2*v] + st[2*v+1];
}

ll query(int v, int tl, int tr, int ql, int qr){
    if(tl > qr || tr < ql){
        return 0;
    }
    if(ql <= tl && tr <= qr){
        return st[v];
    }
    int tm = mid(tl, tr);
    return query(2*v, tl, tm, ql, qr) + query(2*v+1, tm+1, tr, ql, qr);
}

ll ans_window(){
    ll ans;

    auto it = t.find_by_order(med);
    auto [median, median_i] = *it;
  
    // number of 
    int lower_values = t.order_of_key({median, -1});
    int upper_values = t.order_of_key({median, N});

    ll q = query(1, 1, distinct, 1, compress[median]);
    //cout <<"q: "<<q<<endl;
    ll to_increment = 1LL * lower_values * median - q;
    ll to_decrement = - 1LL * (k-upper_values) * median + query(1, 1, distinct, compress[median], distinct);
    
    ans = to_increment + to_decrement;

    return ans;
}

void solve(){
    compression();
    
    med = (k-1)/2;

    for(int i=1; i<=n; i++){
        if (i > k) {
            int j = i-k;
            t.erase({in[j], j});
            update(1, 1, distinct, compress[in[j]], -in[j]);
        }
        t.insert({in[i], i});
        update(1, 1, distinct, compress[in[i]], in[i]);
        if (i >= k) {
            cout << ans_window() << ' ';
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin>>n>>k;
    for(int i=1; i<=n; i++){
        cin>>in[i];
    }
    solve();
}
