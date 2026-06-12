#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MOD = 1e9+7;
const int N = 5e3+1;
const int P =7e2;

int main(){
    ios::sync_with_stdio(0); cin.tie(0);

    vector<int> pr, lp(N+1), id(N+1);
    for(int i=2; i<=N; ++i){
        if(lp[i]==0){
            lp[i]=i;
            id[i] = pr.size();
            pr.push_back(i);
        }
        for(int j=0; i*pr[j]<=N; ++j){
            lp[i*pr[j]] = pr[j];
            if(pr[j]==lp[i]) break;
        }
    }

    
    int n;    cin >>n;
    vector<int> v(n);    for(auto &i: v) cin>>i;

    vector<bitset<P>> basis(P);
    int dim = 0;
    
    for(int x: v){
        bitset<P> m;
        int tmp =x;
        while(tmp>1){
            int p = lp[tmp];
            int c =0 ;
            while(tmp % p == 0){
                tmp /= p;
                c++;
            }
            if(c&1){
                m.set(id[p]);
            }
        }

        //

        for(int i=P-1; i>=0; i--){
            if(m[i]){
                if (!basis[i][i]){
                    basis[i] = m;
                    dim++;
                    break;
                }
                m ^= basis[i];
            }
        }
    }

    ll a = 2, b = n - dim;
    ll res = 1;
    while(b){
        if(b&1){
            res = res * a % MOD;
        }
        a = a*a % MOD;
        b>>=1;
    }


    cout << res << '\n';
    
}
