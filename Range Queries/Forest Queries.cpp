#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
// vector<vector<ll>> grid;
vector<vector<ll>> pref;
ll n, q;
ll solve(){
    ll tl_x, tl_y, br_x, br_y;
    cin>>tl_x>>tl_y>>br_x>>br_y;

    return pref[br_x][br_y] - pref[br_x][tl_y - 1] - pref[tl_x - 1][br_y] + pref[tl_x - 1][tl_y - 1];
}
int main(){
    ios_base::sync_with_stdio(false);cin.tie(nullptr);
    cin>>n>>q;
    // grid.assign(n, vector<ll>(n,0));
    // for(int r=0;r<n;r++){
    //     for(int c=0;c<n;c++){
    //         char ch;cin>>ch;
    //         grid[r][c]= ch=='*';
    //     }
    // }

    pref.assign(n+1, vector<ll>(n+1,0));
    for(int r=0;r<n;r++){
        for(int c=0;c<n;c++){
            char ch; cin>>ch;
            pref[r+1][c+1] = ch=='*';
            pref[r+1][c+1] += pref[r][c+1] + pref[r+1][c] - pref[r][c];
            // cout<<pref[r+1][c+1]<<' ';
        }
        // cout<<'\n';
    }

    while(q--)
        cout<< solve()<<'\n';
    return 0;
}