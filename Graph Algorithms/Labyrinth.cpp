#include<bits/stdc++.h>
using namespace std;
using ll = long long;
typedef pair<int,int> ii;
typedef vector<ll> vll;
typedef vector<vll> vvll;
const int INF = INT_MAX ;
#define fi first
#define se second
#define fori(i,a,b) for(int i=a;i<b;i++)
const int R[]{0,1,0,-1}, C[]{1,0,-1,0};
#define all(v) v.begin(), v.end()
void solve(){
  int n, m; cin>>n>>m;
  ii B,A;
  vvll dis(n, vll(m,INF));
  vector<vector<ii>> papa (n, vector<ii>(m));
  queue<ii> q;
  fori(i,0,n){
	string s; cin>>s;
	fori(j,0,m){
	  if (s[j]=='A'){
		dis[i][j]=0;
		A={i,j};
		q.push(A);
	  }
	  if (s[j]=='B'){
		B = {i,j};
	  }
	  if (s[j]=='#'){
	    dis[i][j]=0;
	  }
	}
  }
  while (!q.empty()){
	auto &[i, j] = q.front();q.pop();
	fori(d,0,4){
	  int x = i+R[d], y = j+C[d];
	  if (x<0||x>=n||y<0||y>=m) continue;
	  if (dis[x][y] > dis[i][j]+1){
		papa[x][y] = {i,j};
		if (x==B.fi && y==B.se){
		  cout<<"YES"<<endl;
		  string s;
		  while (x != A.fi || y != A.se){
			// x= row, y=col
			auto &[nx, ny] = papa[x][y];
			//cout << nx <<' '<<ny<<endl;
			if (ny>y){
			  s+="L";
			}else if (x==nx){
			  s+="R";
			}else if (nx>x){
			  s+="U";
			}else{
			  s+="D";
			}
			x = nx; y = ny;
		  }
		  reverse(all(s));
		  cout <<s.length()<<endl;
		  cout <<s<<endl;
		  return;
		}
		dis[x][y]=dis[i][j]+1;
		q.push({x,y});
	  }
	}
  }
  cout <<"NO"<<endl;
}
int main(){
  ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
  solve();
  return 0;
}
