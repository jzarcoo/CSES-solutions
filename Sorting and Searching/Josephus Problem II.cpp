#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
typedef tree<
    ll,
    null_type,
    less<ll>,
    rb_tree_tag,
    tree_order_statistics_node_update
    > ordered_set;
int main(){
    ios_base::sync_with_stdio(false);cin.tie(nullptr);
    int n, k; cin>>n>>k;
    ordered_set tree;
    for(int i=1; i<=n;i++)
        tree.insert(i);
    ll target = 0;
    while(tree.size()){
        target = (target + k) % tree.size();
        auto it = tree.find_by_order(target);
        cout << *it << ' ';
        tree.erase(it);
    }
}

