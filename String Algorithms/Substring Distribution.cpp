#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXLEN = 1e5;
struct state{
    int len, link;
    map<char,int> next;
};
state st[MAXLEN*2];
int sz, last;
void sa_init(){
    sz = 0;
    st[0].len=0;
    st[0].link = -1;
    sz++;
    last=0;
}
void sa_extend(char c) {
    int cur = sz++;
    st[cur].len = st[last].len + 1;
    int p = last;
    while (p != -1 && !st[p].next.count(c)) {
        st[p].next[c] = cur;
        p = st[p].link;
    }
    if (p == -1) {
        st[cur].link = 0;
    } else {
        int q = st[p].next[c];
        if (st[p].len + 1 == st[q].len) {
            st[cur].link = q;
        } else {
            int clone = sz++;
            st[clone].len = st[p].len + 1;
            st[clone].next = st[q].next;
            st[clone].link = st[q].link;
            while (p != -1 && st[p].next[c] == q) {
                st[p].next[c] = clone;
                p = st[p].link;
            }
            st[q].link = st[cur].link = clone;
        }
    }
    last = cur;
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    string s; cin>>s;
    sa_init();
    for(char c: s){
        sa_extend(c);
    }
    vector<ll> cnt(s.size()+2);
    for(int i=1; i<sz; i++){
        cnt[st[st[i].link].len + 1]++;
        cnt[st[i].len + 1]--;
    }
    for(int i=1; i<= s.size(); i++){
        cnt[i] += cnt[i-1];
        cout << cnt[i] << ' ';
    }
}
