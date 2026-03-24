#include<bits/stdc++.h>
using namespace std;
#define fori(i,a,b) for(int i=a;i<=b;i++)
int n;
void solve(){
    if (n == 1) {
        cout << "1\n"; 
        return;
    }
    if (n < 4) {
        cout << "NO SOLUTION\n"; 
        return;
    }
    fori(i, 2, n) {
        if (i % 2 == 0) {
            cout << i << " "; 
        }
    }
    fori(i, 1, n) {
        if (i % 2 == 1) {
            cout << i << " "; 
        }
    }
    cout << "\n";
}
int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin >> n;
    solve();
    return 0;
}