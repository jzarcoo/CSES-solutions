#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> ii;
struct Room {
  int s, e, i;
  Room(int s,int e, int i) : s(s),e(e),i(i) {}
};
vector<Room> in;
int main(){
  ios_base::sync_with_stdio(0); cin.tie(0);
  int n; cin>>n;
  vector<int> ans(n);
  for(int i=0; i<n;i++){
	int s,e;cin>>s>>e;
	in.emplace_back(s,e,i);
  }
  sort(in.begin(), in.end(), [&](const Room &a, const Room &b){
	if(a.s==b.s) return a.e<b.e;
	return a.s<b.s;
  });
  int mx = 0;
  priority_queue<ii, vector<ii>, greater<ii>> pq; // departure, room
  for(auto &[s,e,i] : in){
	if(!pq.empty() && s > pq.top().first){
	  auto [d, r] = pq.top(); pq.pop();
	  ans[i] = r;
	  pq.push({e, r});
	}else{
	  pq.push({e, ++mx});
	  ans[i]=mx;
	}
  }
  cout<<mx<<endl;
  for(int x:ans)cout<<x<<' ';
  return 0;
}
