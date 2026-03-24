#include<bits/stdc++.h>
using namespace std;
#define sz(x) (int) x.size()
using ll=long long;
using vll = vector<ll>;
string txt, pat;
vll lps;
ll n, m;
void crealps(){
    ll len = 0, i = 1;
    lps[0] = 0;
    while (i < m) {
        if (pat[i] == pat[len]) lps[i++] = ++len;
        else if (len) len = lps[len - 1];
        else lps[i++] = 0;
    }
}
ll solve(){
    crealps();
    ll i=0,j=0;
    ll ans=0;
    while (i < n) {
        if (txt[i] == pat[j]) {
            i++, j++;
            if (j == m) {
                ans++;
                j = lps[j - 1];
            }
        } else {
            if (j) j = lps[j - 1];
            else i++;
        }
    }
    return ans;
}
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin >> txt >> pat;
    n = sz(txt), m = sz(pat);
    lps.resize(m);
    cout<< solve() << '\n';
    return 0;
}