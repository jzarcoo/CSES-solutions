#include<bits/stdc++.h>
using namespace std;
#define fori(i,a,b) for(int i=a; i<b;i++)
int main(){
  ios_base::sync_with_stdio(false);cin.tie(nullptr);
  int n; cin>>n;
  queue<int> q;
  fori(i,0,n) q.push(i+1);
  bool f = false;
  while(!q.empty()){
	int x = q.front(); q.pop();
	if (f) cout << x <<' ';
	else q.push(x);
	f = !f;
  }
  return 0;
}
