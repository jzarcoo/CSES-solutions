#include<bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n; cin>>n;
    vector<int> code(n-2), deg(n+1,1);
    for(int i=0; i<n-2; i++){
        cin>>code[i];
        ++deg[code[i]];
    }
    int ptr=1;
    while(deg[ptr]!=1)ptr++;
    int mini = ptr;
    for(int v: code){
        cout << v<<' '<<mini<<'\n';
        if(--deg[v]==1 && v <ptr)
            mini = v;
        else{
            ptr++;
            while(deg[ptr]!=1)ptr++;
            mini = ptr;
        }
    }
    cout << n<<' '<<mini<<'\n';
}
