#include <bits/stdc++.h>
using namespace std;
long double proba[101][601], ans=0;
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n, a, b; cin>>n>>a>>b;
    proba[0][0]=1.0;
    for(int tiros=1; tiros<=n; tiros++){
        for(int suma=1; suma<=b; suma++){
            for(int dado=1; dado<=min(6,suma); dado++){
                proba[tiros][suma]+=proba[tiros-1][suma-dado];
            }
            proba[tiros][suma] /= 6;
        }
    }
    for(int i=a; i<=b; i++){
        ans += proba[n][i];
    }
    cout<<fixed<<setprecision(6)<<ans;
}
