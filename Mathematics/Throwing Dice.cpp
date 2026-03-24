#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vll;
typedef vector<vll> vvll;
#define sz(a) (int)a.size()
#define fori(i,a,b) for(int i=a; i<b; i++)
const int MOD=1e9+7;
ll n;
void matmul(vvll &a, const vvll &b){
    int n = sz(a), m = sz(a[0]), p=sz(b[0]);
    assert(m==sz(b));
    vvll c(n, vll(p, 0));
    fori(i,0,n){
        fori(j,0,p){
            fori(k,0,m){
                c[i][j] = (c[i][j] + a[i][k]*b[k][j]) % MOD;
            }
        }
    }
    a=c;
}
struct Matrix{
    vvll mat;
    Matrix(vvll a) : mat(a) {}
    Matrix(int n, int m){
        mat.assign(n, vll(m));
    }
    int rows(){return sz(mat);}
    Matrix operator*=(const Matrix &o){
        matmul(mat, o.mat);
        return *this;
    }
    static Matrix makeiden(int n){
        Matrix res(n,n);
        fori(i,0,n) res.mat[i][i]=1;
        return res;
    }
    Matrix binpow(ll b){
        Matrix a = *this,
            res = makeiden(rows());
        while(b){
            if(b&1) res*=a;
            a*=a;
            b>>=1;
        }
        return res;
    }
};
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    cin>>n;
    Matrix rec({
            {0,1,0,0,0,0},
            {0,0,1,0,0,0},
            {0,0,0,1,0,0},
            {0,0,0,0,1,0},
            {0,0,0,0,0,1},
            {1,1,1,1,1,1} 
        });
    Matrix rec_n = rec.binpow(n);
    vvll ini(6, vll(1));
    ini[0][0] = 1;
    fori(i,1,6){
        fori(j,1,7){
            if (i-j>=0){
                ini[i][0] += ini[i-j][0];
            }
        }
    }
    Matrix vini(ini);
    rec_n*=vini;
    cout<<rec_n.mat[0][0];
}
