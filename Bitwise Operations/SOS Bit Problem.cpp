#include<bits/stdc++.h>
using namespace std;
const int LOG= 20;
int sos[1<<LOG], sup[1<<LOG];
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n; cin>>n; vector<int> v(n);
    for(int i=0; i<n; i++){
        cin>>v[i];
        sos[v[i]]++;
        sup[v[i]]++;
    }
    for(int i=0; i<LOG; i++){
        for(int x = 0; x < (1<<LOG); x++){
            if(x & (1<<i)){
                sos[x] += sos[x ^ (1<<i)];
            }
            if(!(x&(1<<i))){
                sup[x] += sup[x^(1<<i)];
            }
        }
    }
    for(int x : v){
        int otra = n - sos[(1<<LOG)-1 - x];
        cout << sos[x] <<' '<<sup[x]<<' '<<otra<<'\n';
    }
}
