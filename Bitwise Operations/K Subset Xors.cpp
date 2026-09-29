#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int B = 30;
int basis[B];
int sz_basis = 0;

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n, k; cin>>n>>k;
    vector<int> v(n);
    for(int &x : v){
        cin>>x;
        for(int i=B-1; i>=0; i--){
            if((x>>i) & 1){
                if((basis[i]>>i) & 1){
                    x ^= basis[i];
                }else{
                    sz_basis++;
                    basis[i] = x;
                    break;
                }
            }
        }
    }
    int nullity = n - sz_basis;

    for(int i=B-1; i>=0; i--){
        if(!basis[i]) continue;
        for(int j=i-1; j>=0; j--){
            if(basis[i] & (1<<j)){
                basis[i] ^= basis[j];
            }
        }
    }

    int limit = 1;
    for(int i=0; i<nullity && limit < k; i++){
        limit = min(k, limit*2);
    }
 
    for(int num=0; num<k; num++){
        int xorr = num/limit; 
        int ans = 0;
        for(int i=0; i<B; i++){
            if(basis[i] & (1<<i)){
                if (xorr & 1){
                    ans ^= basis[i];
                }
                xorr>>=1;
            }
        }
        cout << ans << ' ';
    }
}
