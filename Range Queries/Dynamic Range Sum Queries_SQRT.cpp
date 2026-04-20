#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n, q; cin>>n>>q;
    vector<int> a(n);
    int len = (int) sqrt(n+.0) + 1;
    vector<ll> b(len, 0);
    for(int i=0; i<n; i++){
        int x; cin>>x;
        a[i]=x;
        b[i / len] += x;
    }
    while(q--){
        int t, l, r; cin>>t>>l>>r;
        if(t==1){
            --l;
            b[l/len]-=a[l];
            a[l]= r;
            b[l/len]+=r;
        }else{
            --l, --r;
            ll sum = 0;
            int bl = l  / len, br = r /len;
            if(bl==br){
                for(int i=l; i<=r; i++){
                    sum += a[i];
                }
            }else{
                for(int i=l, end=(bl+1)*len; i<end; i++){
                    sum+=a[i];
                }
                for(int i = bl+1; i<=br-1; i++){
                    sum += b[i];
                }
                for(int i=(br*len); i<=r; i++){
                    sum += a[i];
                }
            }
            cout << sum << '\n';
        }
    }
}
