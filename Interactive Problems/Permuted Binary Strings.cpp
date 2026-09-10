#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
int n;
void ask(string &s){
    cout << "? " << s << endl;
    cout.flush();
    cin>>s;        
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin>>n;
    vector<int> ans(n, 0);
    int pot = 1;
    for(int bit = 1; bit <= 10; bit++){
        string s(n, '0');
        bool same = true;
        for(int num=1; num<=n; num++){
            if(num & (1 << (bit-1))){
                s[num-1] = '1';
                same = false;
            }
        }
        if(same) break;
        ask(s);
        for(int i=0; i<n; i++){
            if(s[i] == '1')
                ans[i] += pot;
        }
        pot <<= 1;
    }
    cout << '!';
    for(int i=0; i<n;  i++){
        cout << ' ' << ans[i];
    }
    cout<<endl;
}
