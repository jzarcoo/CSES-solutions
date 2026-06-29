#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e5;
const int MOD =1e9+7;
vector<int> lp(N+1), pr, cnt(N+1);
ll binpow(ll a, ll b, ll m){
    ll r=1;
    a%=m;
    while(b){
        if(b&1)r=r*a%m;
        a = a*a%m, b>>=1;
    }
    return r;
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    for(int i=2; i<=N; i++){
        if(lp[i]==0){
            lp[i]=i;
            pr.push_back(i);
            cnt[i]=1;
        }
        for(int j=0; i*pr[j]<=N; j++){
            int p = pr[j];
            int x = i*p;
            lp[x] = p;
            if(p==lp[i]){
                cnt[x] = cnt[i] + 1;
                break;
            }else{
                cnt[x] = 1;
            }
        }
    }    
    int n; cin>>n;
    vector<int> p(n); for(auto &i: p)  cin>>i;
    vector<bool> vis(n);
    map<int,int> lcmm;
    for(int i=0; i<n; i++){
        int len = 0;
        int cur = i;
        while(!vis[cur]){
            vis[cur] = 1;
            len++;
            cur = p[cur]-1;
        }
        if(len){
            int tmp = len;
            while(tmp>1){
                int p = lp[tmp];
                int e = cnt[tmp];
                lcmm[p] = max(e, lcmm[p]);
                tmp /= binpow(p, e, MOD);
            }
        }
    }
    ll r =1;
    for(auto &[k, v]: lcmm){
        r = r* binpow(k, v, MOD) % MOD;
    }
    cout << r << '\n';
        
}
