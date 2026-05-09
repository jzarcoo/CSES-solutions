#include<bits/stdc++.h>
using namespace std;
const int N = 2e5+1;
int pa[N], len[N];
int get(int x){
    return x == pa[x] ? x : pa[x] = get(pa[x]);
}
void join(int a, int b){
    a = get(a), b=get(b);
    if(a==b) return;
    pa[b] = a;
    len[a] += len[b];
}

int main(){
    fill(len, len+N, 1);
    iota(pa, pa+N, 0);
    int n;
    scanf("%d", &n);
    vector<pair<int, pair<int,int>>> edges;
    for(int i=1; i<n; i++){
        int a, b, w;
        scanf("%d %d %d", &a, &b, &w);
        edges.emplace_back(w, make_pair(a, b));
    }
    sort(rbegin(edges), rend(edges));
    long long res = 0;
    for(auto &[w,p] : edges){
        auto [a, b] = p;
        res += 1LL * w * len[get(a)]  * len[get(b)];
        join(a, b);
    }
    printf("%lld\n", res);
}
