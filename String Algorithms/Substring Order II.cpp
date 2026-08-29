#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

#define sz(z)(int)z.size()

const int MAXLEN = 1e5+5;
const int MAXSTATE = 2*MAXLEN;

struct state{
    // longest string in the equivalence class
    int len;
    //  longest suffix that is in another equivalence class
    int link;
    map<char, int> go;
};

state s[MAXSTATE];
int last;
int nodes;

string str;
ll k;

// cnt := size of the set endpos(v) / number of terminal positions of the strings in equivalence class v
ll cnt[MAXSTATE];
// order of states by length
int order[MAXSTATE];
// dp[v] := number of substrings of v
ll dp[MAXSTATE];

void extend(const char &c){
    int p = last;
    // new equivalence class
    int cur = nodes++;
    cnt[cur] = 1;
    s[cur].len = s[last].len + 1;
    // find link
    while(p!=-1 && !s[p].go.count(c)){
        s[p].go[c] = cur;
        p = s[p].link;
    }
    if (p==-1){
        /*
         * The transition with c was added to all suffixes of s.
         * The character c hasn't been part of the string s before
         */
        s[cur].link = 0;
    }else{
        int before = s[p].go[c];
        // continuous transition
        if(s[before].len == s[p].len + 1){
            s[cur].link = before;
        }else{
            // before is non-continuous, 
            int clone = nodes++;
            s[clone].go = s[before].go;
            s[clone].len = s[p].len + 1;
            s[clone].link = s[before].link;

            s[before].link = s[cur].link = clone;
            // redirect transitions to clone
            while(p!= -1 && s[p].go[c] == before){
                s[p].go[c] = clone;
                p = s[p].link;
            }
        }

    }
    last = cur;
}

void build(){
    s[0].link = -1;
    s[0].len = 0;
    nodes = 1;
    last = 0;
    for(const char &ch : str){
        extend(ch);
    }
}

void sorting(){
    vector<int> bucket(sz(str) + 1);
    for(int v=0; v<nodes; v++){
        bucket[s[v].len]++;
    }
    for(int i=1; i <= sz(str); i++){
        bucket[i] += bucket[i-1];
    }
    for(int v=nodes-1; v>=0; v--){
        order[--bucket[s[v].len]] = v;
    }
}

void solve(){
    for(int i=nodes-1; i>=0; i--){
        int v = order[i];
        if(s[v].link>=0){
            cnt[s[v].link] += cnt[v];
        }
        dp[v] = cnt[v];
        for(auto &[ch, to] : s[v].go){
            dp[v] += dp[to];
        }
    }
    // kth
    string ans;
    int v = 0;
    while(k>0){
        for(auto &[ch, to] : s[v].go){
            // number of distinct substrings in to
            ll num = dp[to];
            if (k > num){
                k -= num;
                continue;
            }
            ans += ch;
            k -= cnt[to];
            v = to;
            break;            
        }
    }
    cout << ans << '\n';
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin>>str;
    cin>>k;
    build();
    sorting();
    solve();
}
