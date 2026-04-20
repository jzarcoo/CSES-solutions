#include<bits/stdc++.h>
using namespace std;
const int N = 1e6;
int cnt[N+1];
int multiples[N+1];
int mobius[N+1];
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    
    int n; cin>>n;
    vector<int> a(n);
    for(int i=0; i<n; i++){
        int x; cin>>x;
        cnt[x]++;
        a[i] = x;
    }

    mobius[1] = -1;
    for(int i=1; i<= N; i++){
        if(mobius[i]){
            mobius[i] = -mobius[i];
            for(int j=2*i; j<=N; j+=i){
                mobius[j] += mobius[i];
            }
        }
        for(int g = i; g<=N; g+=i){
            multiples[i] += cnt[g];
        }
    }
    
    long long ans=0;
    for(int i=1; i<=N; i++){
        long long p = 1LL * multiples[i] * (multiples[i] - 1) / 2;
        ans += p * mobius[i];
    }
    cout << ans << '\n';
}
