#include<bits/stdc++.h>
using namespace std;
using cd = complex<double>;
using poly = vector<cd>;
const double PI = acos(-1.0);    
int n, m;
void fft(poly &p, int inv){
    int n = p.size();
    for(int i=1, j=0; i<n-1; i++){
        for(int k=n>>1; (j^=k) <k; k>>=1);
        if(i<j) swap(p[i], p[j]);
    }
    poly wp(n>>1);
    for(int k=1;k<n; k<<=1){
        for(int j=0; j<k; ++j){
            wp[j] = polar(1.0, PI*j/k*inv);
        }
        for(int i=0; i<n; i+=k<<1){
            for(int j=0; j<k; ++j){
                cd t = p[i+j+k] * wp[j];
                p[i+j+k] = p[i+j] - t;
                p[i+j]+=t;
            }
        }
    }
    if(inv == -1){
        for(int i=0; i<n; ++i){
            p[i]/=n;
        }
    }
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin>>n>>m;
    int tot = 1;
    while(tot < n+m-1) tot<<=1;
    poly A(tot), B(tot);
    for(int i=0; i<n; i++){
        cin>>A[i];
    }
    for(int i=0; i<m; i++){
        cin>>B[m-1-i];
    }
    fft(A, 1); fft(B, 1);
    for(int i=0; i<tot; i++)
        A[i]*=B[i];
    fft(A, -1);
    for(int i=0; i<n+m-1; i++){
        cout<<(unsigned long long)round(A[i].real()) << ' ';
    }
}
