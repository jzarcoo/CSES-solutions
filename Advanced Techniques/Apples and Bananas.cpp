#include<bits/stdc++.h>
using namespace std;
using cd = complex<double>;
const double PI = acos(-1);
#define fori(i,a,b) for(int i=a; i<b;i++)
#define sz(a) (int) a.size()
void fft(vector<cd> &a, bool invert){
  int n = sz(a);
  for(int i=1, j=0; i<n; i++){
	int bit = n>>1;
	for(; j & bit; bit>>=1) j^=bit;
	j^=bit;
	if (i < j) swap(a[i], a[j]);
  }
  for(int len = 2; len <= n; len<<=1){
	double ang = 2 * PI / len * (invert ? -1 : 1);
	cd wlen(cos(ang), sin(ang));
	for(int i=0; i<n; i+=len){
	  cd w(1);
	  fori(j,0,len/2){
		cd u = a[i+j], v = a[i+j+len/2] * w;
		a[i+j] = u+v;
		a[i+j+len/2] = u-v;
		w *= wlen;
	  }
	}
  }
  if (invert)
	for(cd &x : a)
	  x /= n;
}
int main(){
  ios_base::sync_with_stdio(0);cin.tie(0);
  int k, n, m; cin>>k>>n>>m;
  int t = 1;
  while (t <= 2* k) t <<=1;
  vector<cd> fa(t), fb(t);
  fori(i,0,n){
	int x; cin>>x; fa[x]+=1;
  }
  fori(i,0,m){
	int x; cin>>x; fb[x]+=1;
  }
  fft(fa, 0); fft(fb,0);
  fori(i,0,t) fa[i] *= fb[i];
  fft(fa,1);
  fori(i,2,2*k+1){
	cout << (long long) (fa[i].real() + 0.5)<<' ';
  }
  return 0;
}
