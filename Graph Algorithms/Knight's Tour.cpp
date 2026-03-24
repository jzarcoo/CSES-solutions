#include<bits/stdc++.h>
using namespace std;
const int R[]{2,2,1,1,-1,-1,-2,-2};
const int C[]{1,-1,2,-2,2,-2,1,-1};
const int N=8, M=8;
int grid[N][N];
int sc, sr;
bool isInside(int r, int c){
    return 0<=r && r<N && 0<=c && c<N;
}
bool isValid(int r, int c){
    return isInside(r,c) && grid[r][c] == 0;
}
int getDegree(int r, int c){
    int s=0;
    for(int d=0; d<M; d++){
        int nr = r + R[d], nc = c + C[d];
        if (isValid(nr,nc)){
            s++;
        }
    }
    return s;
}
bool knight_tour(int r, int c, int step=2){
    if (step == N*N+1) return 1;
    vector<array<int,3>> neighbors;
    for(int d=0; d<M; d++){
        int nr = r + R[d], nc = c + C[d];
        int deg = getDegree(nr, nc);
        if (isValid(nr, nc))
            neighbors.push_back({deg, nr, nc});
    }
    sort(neighbors.begin(), neighbors.end());
    for(auto &[m, nr, nc] : neighbors){
        grid[nr][nc] = step;
        if (knight_tour(nr, nc, step+1))
            return 1;
        grid[nr][nc] = 0;
    }
    return 0;
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin>>sc>>sr;sc--,sr--;
    grid[sr][sc] = 1;
    knight_tour(sr, sc);
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            if(j) cout <<' ';
            cout << grid[i][j];
        }
        if(i!=N-1)cout<<'\n';
    }
}
