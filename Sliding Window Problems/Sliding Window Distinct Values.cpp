#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using vll=vector<ll>;
#define FOR(i,a,b) for(int i=a; i<b;i++)
#define cinv(a) for(auto &i:a) cin>>i
#define sz(a) (int) a.size()
#define rz resize
ll n, k;
vll arr;
void solve(){
    map<ll,ll> freq;
    FOR(i, 0, n){
        ++freq[arr[i]];
        if (i-k+1 >= 0) {
            cout << sz(freq) << ' ';
            if(--freq[arr[i-k+1]]==0) freq.erase(arr[i-k+1]);
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
