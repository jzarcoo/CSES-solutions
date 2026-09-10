#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
int n;
int ask(int l, int r){
    cout << l << ' ' << r << endl;
    cout.flush();
    int inv; cin>>inv;
    if(inv == 0) {
        exit(0);
    }
    return inv;
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin>>n;
    int prev = ask(1,1);
    int pairs = 0;
    for(int i=2; i<=n; i++){
        pairs += i-1; // lol, i haven't noticed
        int cur = ask(1, i);
        int sub = (pairs + prev - cur) >> 1;
        // restore
        ask(1, i);
        int pos = i - sub;
        if(pos < i){
            // place i
            ask(i-sub, i);
            // fix
            prev = ask(i-sub+1, i);
        }        
    }
}
