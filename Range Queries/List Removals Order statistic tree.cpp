#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
typedef vector<int> vi;
typedef tree<int, null_type, less<int>, rb_tree_tag,
tree_order_statistics_node_update> indexed_set;
#define re(v) for(auto &i:v) cin>>i;
#define fori(i,a,b) for(int i=a;i<b;i++)
int N;
indexed_set s;
int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    cin>>N;
    vi arr(N); re(arr);
    vi queries(N); re(queries);
    fori(i,0,N){
        s.insert(i);
    }
    for(int q:queries){
        int k = *s.find_by_order(q-1);
        cout << arr[k] << " ";
        s.erase(k);
    }
    return 0;
}
