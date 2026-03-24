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
/*
  Input:

8 3
2 4 3 5 8 1 2 1

  Output:

  2 2 5 7 7 1

*/
indexed_set s;
int n, k;
ll sum = 0;
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin>>n>>k;
    vector<int> v(n); for(auto &i: v)cin>>i;
    for(int i=0; i<n; i++){
        sum += v[i];
        s.insert({v[i],i});
        if(i-k+1>=0){
            auto it = s.find_by_order((k-1) /2);
            p ans  = *it;
            cout << abs(k*(ans.first))  << ' '<<sum<<endl;
            s.erase({v[i-k+1], i-k+1});
            sum -= v[i-k+1];
        }
    }
    return 0;
}
