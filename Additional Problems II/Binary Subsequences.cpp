#include<bits/stdc++.h>
using namespace std;
int trace_len(int a, int b){
  if (a==b) return 0;
  if (a>b) return 1 + trace_len(a-b,b);
  return 1 + trace_len(a, b-a);
}
string trace(int a, int b){
  if (a==b) return "";
  if (a>b) return "1" + trace(a-b,b);
  return "0" + trace(a, b-a);
}
int main(){
  ios_base::sync_with_stdio(0); cin.tie(0);
    int n;cin>>n;
    int b,mn=++n;
    for(int a=1;a<=n;a++) {
        if(gcd(a,n+1)!=1)continue;
        int len=trace_len(a,n-a+1);
        if(len<mn) mn=len, b=n-a+1;
    }
    cout<<trace(n-b+1,b)<<"\n";
}
