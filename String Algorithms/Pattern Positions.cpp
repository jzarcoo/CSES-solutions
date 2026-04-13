#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
#define all(z)z.begin(), z.end()
#define sz(z) (int )z.size()
#define FOR(i,a,b) for(int i=a; i<b; i++)
#define ROF(i,a,b) for(int i=a; i>b; i--)
struct ST{
    vi st; int n, neu = INT_MAX;
    ST(){}
    void init(vi & a){
        n = 1;
        while(n<sz(a))n<<=1;
        st.assign(2*n, neu);
        FOR(i,0,sz(a)) {st[n+i] = a[i];}
        ROF(i,n-1, 0) {st[i] = min(st[2*i], st[2*i+1]);}
    }
    int query(int l, int r){
        if(l>r) return neu;
        int ans = neu;
        for(l+=n, r+=n; l<=r; l/=2, r/=2){
            if(l&1) ans = min(ans, st[l++]);
            if(!(r&1)) ans = min(ans, st[r--]);
        }
        return ans;
    }
};
int cmp(const string &t, const string &p, int k){
    int n = sz(t), m =sz(p);
    FOR(i,0,m){
        if(k+i>=n) return -1;
        if(t[k+i] != p[i])
            return t[k+i] < p[i] ? -1 : 1;
    }
    return 0;
}
struct SA{
    string S; int N; vi sa,isa;
    ST R;
    SA(string s) : S(s), N(sz(S)+1){
        sa = isa = vi(N); sa[0] = N-1; iota(1+all(sa), 0);
        sort(1+all(sa), [&](int a, int b){return S[a]<S[b];});
        FOR(i,1,N){ int a = sa[i-1], b = sa[i];
            isa[b] = i>1 && S[a]==S[b] ? isa[a] : i; }
        for(int len = 1; len<N; len*=2){
            vi s(sa), is(isa), pos(N); iota(all(pos), 0);
            for(int t : s){int T=t-len; if(T>=0) sa[pos[isa[T]]++] = T;}
            FOR(i,1,N){int a = sa[i-1], b = sa[i];
                isa[b] = is[a]==is[b] && is[a+len]==is[b+len] ? isa[a] : i;}
        }
        R.init(sa);
    }
    int find(const string &p){
        int l = 1, r = N-1, ini = -1, fin  = -1;
        while(l<=r){
            int m = l +(r-l)/2, res = cmp(S, p, sa[m]);
            if(res>=0){
                if(res ==0) ini = m;
                r = m-1;
            }else l=m+1;
        }
        if(ini == -1) return -1;
        l = 1, r = N-1;
        while(l<=r){
            int m = l + (r-l)/2, res = cmp(S, p, sa[m]);
            if(res<=0){
                if (res ==0) fin = m;
                l = m+1;
            }else r = m-1;
        }
        return 1 + R.query(ini, fin);
    }
};
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    string t; cin>>t;
    int n; cin>>n;
    SA s(t);
    while(n--){
        string p; cin>>p;
        cout << s.find(p) << '\n';
    }
}
