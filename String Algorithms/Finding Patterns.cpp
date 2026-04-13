#include<bits/stdc++.h>
using namespace std;
const int M = 26;
const int N = 6e5;
int nodes = 1;
int trie[N][M], fail[N];
vector<int> leaf[N], g[N];
int seen[N], ans[N];
string s;
void add_word(const string &word, const int &idx){
    int node = 1;
    for(char ch :word){
        if(trie[node][ch-'a'] == 0) {
            trie[node][ch-'a'] = ++nodes;
        }
        node = trie[node][ch-'a'];
    }
    leaf[node].push_back(idx);
}
void build(){
    queue<int> q;
    int node = 1;
    fail[node]=1;
    for(int i=0; i<M; i++){
        if(trie[node][i]){
            fail[trie[node][i]] = node;
            q.push(trie[node][i]);
        }else{
            trie[node][i] = 1;
        }
    }
    while(!q.empty()){
        int node =q.front(); q.pop();
        for(int i=0; i<M; i++){
            if(trie[node][i]){
                fail[trie[node][i]] = trie[fail[node]][i];
                q.push(trie[node][i]);
            }else{
                trie[node][i] = trie[fail[node]][i];
            }
        }
    }
    for(int i=2; i<=nodes; i++){
        g[fail[i]].push_back(i);
    }
}
void search(){
    int node = 1;
    for(char ch:s){
        node = trie[node][ch-'a'];
        seen[node]++;
    }
}
int dfs(int node){
    int sol = seen[node];
    for(int son : g[node]) {
        sol += dfs(son);
    }
    for(int idx : leaf[node]){
        ans[idx] = sol;
    }
    return sol;
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin>>s;
    int n; cin>>n;
    vector<string> words(n);
    for(int i=0; i<n; i++){
        cin>>words[i];
        add_word(words[i], i);
    }
    build();
    search();
    dfs(1);
    for(int i=0; i<n; i++){
        cout << (ans[i] ? "YES" : "NO") << '\n';
    }
}
