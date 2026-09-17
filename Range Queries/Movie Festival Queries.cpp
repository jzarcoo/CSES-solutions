#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
const int T = 1 << 20;
const int LOG = 19;
int up[N][LOG+1];
int tree[2*T];
struct movie{
    int s, e, i;
};

int n, q;
vector<movie> movies;

void change(int s, int movie_id){
    s+=T;
    if(tree[s] == n || movies[movie_id].e < movies[tree[s]].e){
        tree[s] = movie_id;
    }
    for(; s > 1; s >>= 1){
        int left = tree[s], right = tree[s^1];
        if(left==n) tree[s>>1] = right;
        else if(right == n) tree[s>>1] = left;
        else
        tree[s>>1] = (movies[left].e < movies[right].e) ? left : right;
    }
}
int query(int l, int r){
    int movie_id = n;
    for(l+=T, r+=T; l<=r; l>>=1, r>>=1){
        if(l & 1){
            if(tree[l] != n){
                movie_id = (movie_id == n || movies[tree[l]].e < movies[movie_id].e) ? tree[l] : movie_id;
            }
            l++;
        }
        if(!(r&1)){
            if(tree[r] != n){
                movie_id = (movie_id == n || movies[tree[r]].e < movies[movie_id].e) ? tree[r] : movie_id;
            }
            r--;
        }
    }
    return movie_id;
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin>>n>>q;
    fill(tree, tree+2*T, n);
    for(int i=0; i<n; i++){
        int s, e; cin>>s>>e;
        movies.push_back({s, e, i});
    }
    sort(movies.begin(), movies.end(), [](const movie &a, const movie &b){
            if(a.e==b.e) return a.s<b.s;
            return a.e < b.e;
            });
    movies.push_back({0, 2*N, n});
    for(int i=n-1; i>=0; i--){
        auto &m = movies[i];
        // cout << m.i << " " <<m.s << " " << i<<endl;
        change(m.s, i);
    }
    for(int i=0;i<n; i++){
        auto &m = movies[i];
        int nxt = query(m.e, T-1);
        //cout << endl;
      //  cout << i << " " << nxt << endl;
        up[i][0] = nxt;
    }
    up[n][0] = n;
    for(int i=1; i<=LOG; i++){
        for(int j=0; j<=n; j++){
            int halfway = up[j][i-1];
            
            if(halfway == n)
                up[j][i] = n;
            else
                up[j][i] = up[halfway][i-1];
        }
    }
    for(int i=0; i<q; i++){
        int l, r; cin>>l>>r;
        int ini = query(l, r);
        if(ini == n || movies[ini].e > r){
            cout << 0 << '\n';
            continue;
        }
        int ans = 1;
        for(int lvl = LOG; lvl>=0; lvl--){
            int jump = up[ini][lvl];
            if(jump!= n && movies[jump].e <= r){
                ini = jump;
                ans += (1<<lvl);
           }
        }
        cout << ans << '\n';
    }
}
