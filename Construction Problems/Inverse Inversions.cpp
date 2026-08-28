#include<bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    long long n, k; cin>>n>>k;
    vector<long long> ans(n, 0);
    long long l=1, r=n;
    for(long long i=0; i<n; i++){
        if(k>=r-l){
            ans[i] = r;
            k -= r-l;
            r--;
        }else{
            ans[i] = l;
            l++;
        }
    }
    for(long long x:ans) cout << x <<' ';
}
