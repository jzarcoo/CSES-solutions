#include<bits/stdc++.h>
using namespace std;
#define sz(x) (int) x.size()
const int K=26;
const int MOD=1e9+7;
struct Vertex {
  int next[K];
  bool out = 0;
  Vertex(){
	memset(next, -1, sizeof next);
  }
};
vector<Vertex> trie(1);
void insert(string word){
  int v=0;
  for(char c: word){
	if (trie[v].next[c-'a'] == -1) {
	  trie[v].next[c-'a'] = sz(trie);
	  trie.emplace_back();
	}
	v = trie[v].next[c-'a'];
  }
  trie[v].out = 1;
}
string s;
int k;
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
	cin>>s>>k;
	int n = sz(s);
	while(k--){
	  string d; cin>>d; insert(d);
	}
	vector<long long> dp(n+1);
	dp[n]=1;
	for(int i=n-1;i>=0;--i){
	  int v = 0;
	  for(int j=i;j<n;++j){
		int c = s[j]-'a';
		if(trie[v].next[c]==-1) break;
		v = trie[v].next[c];
		if (trie[v].out) dp[i] = (dp[i] + dp[j+1]) % MOD;
	  }
	}
	cout<<dp[0]<<'\n';
    return 0;
}
