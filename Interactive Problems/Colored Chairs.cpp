#include<bits/stdc++.h>
using namespace std;
int n;
bool fi;
bool ask(int x){
    cout << "? "<<x<<'\n';
    cout.flush();
    char c; cin>>c;
    return c=='R';
    // r ==1, b==0
}
void print(int x){
    cout << "! "<<x<<'\n';
}
void solve(){
    int l = 0, r = n;
    while(l<r){
        int m = l + (r-l+1)/2;
        bool keep_order = (m&1) ? ask(m)==fi : ask(m) != fi;
        if(keep_order){
            l = m;
        }else{
            r = m - 1;
        }
    }
    print(l);
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin>>n;
    fi = ask(1);
    solve();    
}
