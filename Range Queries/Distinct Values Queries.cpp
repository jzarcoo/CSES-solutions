#include<bits/stdc++.h>
using namespace std;
int block_size;
struct Query{
    int l,r,i;
    bool operator<(Query o) const {
        if (l / block_size != o.l / block_size) return l < o.l;
        return ( l  / block_size & 1) ? (r < o.r) : (r > o.r);
    }
};
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n, q; cin>>n>>q;
    block_size = (int) sqrt(n+.0) + 1;
    vector<int> a(n), answers(q);
    vector<Query> queries(q);
    for(int i=0; i<n; i++){
        int x; cin>>x;
        a[i]=x;
    }
    vector<int> aux = a;
    sort(aux.begin(), aux.end());
    aux.erase(unique(aux.begin(), aux.end()), aux.end());
    for(int i=0; i<n; i++){
        a[i] = lower_bound(aux.begin(), aux.end(), a[i]) - aux.begin();
    }
    for(int i=0; i<q; i++){
        int l, r; cin>>l>>r;
        queries[i] = Query{l-1,r-1,i};
    }
    sort(queries.begin(), queries.end());
    vector<int> dif(aux.size(), 0);
    int cnt = 0;
    auto remove = [&](int i){
        if(--dif[a[i]] == 0) cnt--;
    };
    auto add = [&](int i){
        if(++dif[a[i]] == 1) cnt++;
    };
    int cur_l = 0;
    int cur_r = -1;
    for(Query q: queries){
        while(cur_l > q.l){
            cur_l--;
            add(cur_l);
        }
        while(cur_r < q.r){
            cur_r++;
            add(cur_r);
        }
        while(cur_l < q.l){
            remove(cur_l);
            cur_l++;
        }
        while(cur_r > q.r){
            remove(cur_r);
            cur_r--;
        }
        answers[q.i] = cnt;
    }
    for(int x : answers){
        cout << x << '\n';
    }
}
