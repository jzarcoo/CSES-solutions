#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n, k; cin>>n>>k;
    vector<int> a(n+1);
    for(int i=1; i<=n; i++){
        cin>>a[i];
    }
    ll ans = 0;
    int l=1;
    map<int,int> freq;
    int dis = 0;
    for(int i=1; i<=n; i++){
        if(++freq[a[i]]==1){
            dis++;
        }
        while(dis>k){
            if(--freq[a[l++]] == 0){
                dis--;
            }
        }
        ans += i-l+1;
    }
    cout << ans << '\n';
}
