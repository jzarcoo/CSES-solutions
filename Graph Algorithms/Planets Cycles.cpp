#include<bits/stdc++.h>
using namespace std;
const int N=2e5;

int n;
int p[N+1];

int ans[N+1];

void dfs(int v, int fi){
    int x = p[v];
    int d = 1;
    while(x!=fi){
        x = p[x];
        d++;
    }
    while(v!=fi){
        ans[v] = d + ans[fi];
        d--;
        v = p[v];
    }
}
void dfs(int v){
    int a = p[v];
    int b = p[p[v]];
    while(a!=b){
        if(ans[a]!=0){
            dfs(v, a);
            return ;
        }
        a=p[a];
        b=p[p[b]];
    }
    // get entry cycle
    a = v;
    int dist = 0;
    while(a!=b){
        dist++;
        a = p[a];
        b = p[b];
    }
    int first = a;

    // CYCLE
    // cycle length
    int len = 1;
    b=p[b];
    while(a!=b){
        b = p[b];
        len++;
    }
    // assign steps
    do{
        ans[a] = len;
        a = p[a];
    }while(a!=b);

    // TREE
    a = v;
    while(a!=b){
        ans[a] = dist + len;
        dist--;
        a = p[a];
    }
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin>>n;
    for(int v=1; v<=n; v++){
        cin>>p[v];
    }
    for(int v=1; v<=n; v++){
        if(ans[v]==0){
            dfs(v);
        }
    }
    for(int v=1; v<=n; v++){
        cout << ans[v] << " \n"[v==n];
    }
}
