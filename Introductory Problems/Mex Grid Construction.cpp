#include<bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int h; cin>>h;
    for(int r=0; r<h; r++){
        for(int c=0; c<h; c++){
            cout << (r^c) << ' ';
        }
        cout << '\n';
    }
}
