#include <bits/stdc++.h>
#define fori(i,a,b) for (int i=a; i<b;i++)
using namespace std;
typedef pair<int,int> ii;
const int R_CHANGE[]{0,1,0,-1};
const int C_CHANGE[]{1,0,-1,0};
int n, m, ans=0;
vector<string> a;
void solve(){
    cin>>n>>m;
    a.resize(n);
    fori(i,0,n){
        cin>>a[i];
    }
    stack<ii> st;
    fori(i,0,n){
        fori(j,0,m){
            if (a[i][j]=='.'){
                ans++;
                st.push({i,j});
                a[i][j]='#';
                while(!st.empty()){
                    ii curr = st.top();st.pop();
                    fori(d,0,4){
                        int r = curr.first + R_CHANGE[d], c = curr.second +C_CHANGE[d];
                        if (r>=0&&r<n&&c>=0&&c<m && a[r][c]=='.'){
                            st.push({r,c});
                            a[r][c]='#';
                        }
                    }
                }
            }
        }
    }
    cout<<ans<<endl;
}
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    solve();
    return 0;
}