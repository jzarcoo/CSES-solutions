#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef pair<int,int> ii;
#define all(z)z.begin(), z.end()
#define sz(z) (int )z.size()
#define FOR(i,a,b) for(int i=a; i<b; i++)
int cmp(const string &t, const string &p, int pos){
    int n = sz(t), m =sz(p);
    FOR(i,0,m){
        if(pos+i>=n) return -1;
        if(t[pos+i] != p[i])
            return t[pos+i] < p[i]  ? -1 : 1;
    }
    return 0;
}
struct SA{
    string S; int N; vi sa, isa;
    SA(string s) : S(s), N(sz(S)+1){
        sa = isa = vi(N); sa[0] = N-1; iota(1+all(sa), 0);
        sort(1+all(sa), [&](int a, int b){return S[a]<S[b];});
        FOR(i,1,N){int a = sa[i-1], b=sa[i];
            isa[b] = i>1 && S[a] == S[b] ? isa[a] : i; }
        for(int len=1; len<N; len*=2){
            vi s(sa), is(isa), pos(N); iota(all(pos), 0);
            for(int t : s){int T=t-len; if(T>= 0) sa[pos[isa[T]]++] = T;}
            FOR(i,1,N){int a=sa[i-1], b=sa[i];
                isa[b] = is[a]==is[b] && is[a+len]==is[b+len] ? isa[a]  : i; }
        }
    }
    ii find_occurrences(const string &p){
        int l = 0, r = N-1, left = -1, right = -1;
        while(l<=r){
            int m = l + (r-l)/2;
            int ans = cmp(S, p, sa[m]);
            if(ans >= 0){
                if(ans == 0) left = m;
                r = m-1;
            }else{
                l = m+1;
            }
        }
        if(left==-1) return {-1,-1};
        l = 0, r = N-1;
        while(l<=r){
            int m = l + (r-l)/2;
            int ans = cmp(S, p, sa[m]);
            if(ans <= 0){
                if(ans == 0) right = m;
                l = m+1;
            }else{
                r = m-1;
            }
        }
        return {left, right};
    }
};

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    string t; cin>>t;
    SA s(t);
    int n; cin>>n;
    while(n--){
        string p; cin>>p;
        auto [l, r] = s.find_occurrences(p);
        cout << (l==-1 ? 0 : r-l+1) <<'\n';
    }
}
