#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;
typedef long long ll;
typedef pair<int,ll> p;
typedef tree<
    p,
    null_type,
    less<p>,
    rb_tree_tag,
    tree_order_statistics_node_update
    > indexed_set;
#define sz(a) (int) a.size()

int n, k;
ll c=0;
indexed_set s;
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin>>n>>k;
    vector<int> v(n); for(auto &i:v) cin>>i;
    for(int i=0; i<n;i++){
        c += sz(s) - s.order_of_key({v[i], LLONG_MAX});
        s.insert({v[i], i});
        if(i-k+1 >= 0){
            cout<<c<<' ';
            c -= s.order_of_key({v[i-k+1], -1});
            s.erase({v[i-k+1], i-k+1});
        }
    }
    return 0;
}
