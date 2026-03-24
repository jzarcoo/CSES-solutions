#include<bits/stdc++.h>
using namespace std;
int freq[26];
int main(){
  ios_base::sync_with_stdio(0);cin.tie(0);
  string s, r; cin>>s;
  for(char c : s) 
	freq[c-'A']++;
  char c=0;
  for(int i=0; i<26;i++){
	if (freq[i]&1){
	  if(c!=0){
		cout << "NO SOLUTION"<<endl;
		return 0;
	  }
	  freq[i]--;
	  c = char('A'+i);
	}
	freq[i]/=2;
	while(freq[i]--)
	  r+= char('A'+i);
  }
  cout << r;
  if (c && r.size()==(s.size()-1)/2)
	cout<< c;
  for(int i= (int)r.size()-1; i>=0;i--) cout<<r[i];
  return 0;
}
