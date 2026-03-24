#include<bits/stdc++.h>
using namespace std;
int n;
void subtree(vector<vector<int>> &t, vector<int> &s, int v=0, int p=-1){
  s[v]=1;
  for(int w:t[v])
	if (w!=p)
	  subtree(t,s,w,v), s[v]+=s[w];
}
int centroid(vector<vector<int>> &t, vector<int> &s, int v=0, int p=-1){
  for(int w:t[v])
	if (w!=p && 2*s[w]>n)
	  return centroid(t,s,w,v);
  return v;
}
int main(){
  ios_base::sync_with_stdio(0); cin.tie(0);
  cin>>n;
  vector<vector<int>> t(n);
  vector<int> s(n);
  for(int i=1; i<n;i++){
	int a, b;cin>>a>>b;
	t[--a].push_back(--b);
	t[b].push_back(a);
  }
  subtree(t, s);
  cout << 1+centroid(t, s)<< endl;
  return 0;
}
