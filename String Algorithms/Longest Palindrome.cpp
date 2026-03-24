#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  string s; cin >> s;
  int n = s.size();
  string t; t.reserve(2 * n + 1);
  for (char c : s) {
	t.push_back('#');
	t.push_back(c);
  }
  t.push_back('#');
  int m = t.size();
  vector<int> p(m);
  int l = 0, r = -1, best_len = 0, best_center = 0;
  for (int i = 0; i < m; i++) {
	int &k = p[i];
    k = (i > r) ? 1 : min(p[l + r - i], r - i + 1);
	while (i - k >= 0 && i + k < m && t[i - k] == t[i + k])
	  k++;
	if (i + k - 1 > r) {
	  l = i - k + 1;
	  r = i + k - 1;
	}
	if (k - 1 > best_len) {
	  best_len = k - 1;
	  best_center = i;
	}
  }
  cout << s.substr((best_center - best_len) / 2, best_len);
  return 0;
}
