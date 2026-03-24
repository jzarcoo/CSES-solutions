#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using pll=pair<ll,ll>;
using vll=vector<ll>;
#define FOR(i,a,b) for(int i=a; i<b;i++)
#define cinv(a) for(auto &i:a) cin>>i
#define sz(a) (int) a.size()
#define rz resize
#define fi first
#define se second
ll n, k;
vll arr;
void solve(){
    auto cmp = [](const pll &a, const pll &b){
        if (a.fi==b.fi){
            return a.se < b.se;
        }
        return a.fi>b.fi;
    };
    map<ll,ll> freq;
    set<pll, decltype(cmp)> val(cmp);
    FOR(i, 0, n){
        ll add = freq[arr[i]]++;
        auto it = val.find({add, arr[i]});
        if (it != val.end()) val.erase(it);
        val.insert({add + 1, arr[i]});
        if (i-k+1 >= 0) {
            cout << val.begin()->se <<' ';
            ll rem = freq[arr[i-k+1]]--;
            auto it = val.find({rem, arr[i-k+1]});
            val.erase(it);
            if (rem != 1){
                val.insert({rem - 1, arr[i-k+1]});
            }
        }
    }
}
int main(){
    ios_base::sync_with_stdio(false);cin.tie(nullptr);
    cin>>n>>k;
    arr.rz(n); cinv(arr);
    solve();
    return 0;
}
