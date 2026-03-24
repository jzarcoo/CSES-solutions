#include<bits/stdc++.h>
using namespace std;
using ll=long long;
#define fori(i,a,b) for(int i=a;i<b;i++)
#define sz(a) (int) a.size()
const int MOD = 1e9+7;
template <typename T> void matmul(vector<vector<T>> &a, const vector<vector<T>>&b){
    int n=sz(a), m=sz(a[0]), p=sz(b[0]);
    assert(m==sz(b));
    vector<vector<T>> c(n, vector<T>(p, 0));
    fori(i,0,n){
        fori(j,0,p){
            fori(k,0,m){
                c[i][j] = (c[i][j] + a[i][k] * b[k][j]) % MOD;
            }
        }
    }
    a=c;
}
template <typename T> struct Matrix{
    vector<vector<T>> mat;
    Matrix(int n, int m){
        mat.resize(n);
        fori(i,0,n) mat[i].resize(m);
    }
    int rows(){return sz(mat);}
    Matrix operator*=(const Matrix &b){
        matmul(mat, b.mat);
        return *this;
    }
    static Matrix makeiden(int n){
        Matrix res(n, n);
        fori(i,0,n){
            res.mat[i][i]=1;
        }
        return res;
    }
    Matrix binpow(ll b) {
        Matrix a = *this;
        Matrix res = makeiden(rows());
        while(b){
            if (b & 1) res *= a;
            a *= a;
            b>>=1;
        }
        return res;
    }
};
void solve(){
    ll n; cin>>n;
    Matrix<ll> Fibo(2,2);
    Fibo.mat[0][0] = 1;
    Fibo.mat[0][1] = 1;
    Fibo.mat[1][0] = 1;
    Fibo.mat[1][1] = 0;
    cout<<Fibo.binpow(n).mat[0][1]<<'\n';
}
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    solve();
    return 0;
}