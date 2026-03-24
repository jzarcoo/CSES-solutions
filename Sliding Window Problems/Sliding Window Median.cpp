#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
typedef pair<int, int> p;
typedef tree<
  p,
  null_type,
  less<p>,
  rb_tree_tag,
  tree_order_statistics_node_update
  > indexed_set;
indexed_set s;
int n, k;
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin>>n>>k;
    vector<int> v(n); for(auto &i: v)cin>>i;
    for(int i=0; i<n; i++){
        s.insert({v[i],i});
        if(i-k+1>=0){
            // 5 -> 2
            // 6 -> 2
            auto it = s.find_by_order((k-1) /2);
            p ans  = *it;
            cout << ans.first  << ' ';
            s.erase({v[i-k+1], i-k+1});
        }
    }
    return 0;
}
