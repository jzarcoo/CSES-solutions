#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1e9+7;
const int N = 2e5+5;
int n;
ll p[N];
ll ways[N];
map<int,int> last;
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin>>n;
    int l = 1;
    p[0] = ways[0] = 1;
    for(int i=1; i<=n; i++){
        int x; cin>>x;
        if (last.count(x) > 0) {
            l = max(l, last[x] + 1);
        }
        last[x] = i;
        ways[i] = p[i-1]; // -p[(l-1)-1]
        if(l-2>=0){
            ways[i] = ((ways[i] - p[l-2]) % MOD + MOD) % MOD;
        }
        p[i] = (p[i-1] + ways[i]) % MOD;
    }
    cout << ways[n] << '\n';
}
