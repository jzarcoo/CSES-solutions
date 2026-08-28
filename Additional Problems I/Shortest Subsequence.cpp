#include<bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    string s, r="";
    cin>>s;
    set<char> st;
    for(const char &ch : s){
        st.insert(ch);
        if(st.size() == 4){
            r+=ch;
            st.clear();
        }
    }
    for(char ch : {'A','C','G','T'}){
        if(st.count(ch) == 0){
            r+=ch;
            break;
        }
    }
    cout << r<<'\n';
}
