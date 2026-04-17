#include<bits/stdc++.h>
using namespace std;
const int INF = 1e9;
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int w, h; cin>>w>>h;
    vector<vector<int>> min_moves(w+1, vector<int>(h+1, INF));
    for(int wc = 0; wc <= w; wc++){
        for(int hc = 0; hc <= h; hc++){
            int &cur = min_moves[wc][hc];
            // square
            if(wc == hc){
                cur = 0;
                continue;
            }
            // vertical: cut x hc, (wc - cut) x hc
            for(int cut = 1; cut < wc; cut++){
                cur = min(cur, 1 + min_moves[cut][hc] + min_moves[wc - cut][hc]);
            }
            // horizontal
            for(int cut = 1; cut < hc; cut++){
                cur = min(cur, 1 + min_moves[wc][cut] + min_moves[wc][hc - cut]);
            }
        }
    }
    cout << min_moves[w][h] << '\n';
}
