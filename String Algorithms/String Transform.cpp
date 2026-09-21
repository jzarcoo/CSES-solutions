#include<bits/stdc++.h>
using namespace std;
#define sz(z) (int) z.size()
const int K = 27;
const int N = 1e6;

int freq[K];
int start[K];
int go[N+1];

string bw;

int id(const char &c){
    return c == '#' ? 0 : c - 'a' + 1;
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin>>bw;
    for(const char &ch : bw){
        freq[id(ch)]++;
    }
    for(int i=1; i < K; i++){
        start[i] = start[i-1] + freq[i-1];
    }
    for(int i=0; i<sz(bw); i++){
        int c = id(bw[i]);
        // go[F] = L
        go[start[c]++] = i;
    }
    string ans;
    int last = go[0];
    for (int i=0; i< sz(bw) - 1; i++) {
        last = go[last];
        ans += bw[last];
    }
    cout << ans << '\n';
}
