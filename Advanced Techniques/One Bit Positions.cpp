#include<bits/stdc++.h>
using namespace std;
using cd = complex<double>;
using poly = vector<cd>;
const double PI= acos(-1.0);
void fft(poly &p, int inv){
    int n = p.size();
    for(int i=1, j=0;i<n-1; i++){
        for(int k=n>>1; (j^=k) < k; k>>=1);
        if(i<j) swap(p[i],p[j]);
    }
    poly wp(n>>1);
    for(int k=1; k<n; k<<=1){
        for(int j=0; j<k;++j)
            wp[j] = polar(1.0, PI*j/k*inv);
        for(int i=0; i<n; i+=k<<1){
            cd w(1);
            for(int j=0; j<k; j++){
                cd t = p[i+j+k] * wp[j];
                p[i+j+k] = p[i+j] - t;
                p[i+j]+=t;
            }
        }
    }
    if(inv==-1){
        for(int i=0; i<n; ++i){
            p[i]/=n;
        }
    }
}
int main(){
    ios::sync_with_stdio(0);
    string s; cin>>s;
    int n = s.size();
    int sz = (n<<1)-1;
    int len = 1;
    while(len < sz) len<<=1;
    poly A(len), B(len);
    for(int i=0; i<n;i++){
        A[i] = s[i] - '0';
        B[i] = s[n-1-i]-'0';
    }
    fft(A, 1); fft(B, 1);
    for(int i=0; i < len; i++){
        A[i]*=B[i];
    }
    fft(A, -1);
    for(int k=1; k<n; k++){
        cout << (unsigned int) round(A[n-1+k].real()) <<' ';
    }
}
