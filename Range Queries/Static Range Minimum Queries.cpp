#include <bits/stdc++.h>
using namespace std;
using ll = long long;
template <class T> class SegmentTree {
    private:
        const T NEUTER = INT_MAX;
        int len;
        vector<T> st;
        T merge(const T &a, const T &b){
            return min(a, b);
        }
        void build(const vector<T> &arr, int at, int tl, int tr){
            if (tl == tr){
                st[at] = arr[tl];
                return;
            }
            int tm = tl + (tr - tl) / 2;
            build(arr, at * 2, tl, tm);
            build(arr, at * 2 + 1, tm + 1, tr);
            st[at] = merge(st[2 * at], st[2 * at + 1]);
        }
        void update(int at, int tl, int tr, int pos, ll val){
            if (tl == tr){
                st[at] = val;
                return;
            }
            int tm = tl + (tr - tl) / 2;
            if (pos <= tm){
                update(at * 2, tl, tm, pos, val);
            }else{
                update(at * 2 + 1, tm + 1, tr, pos, val);
            }
            st[at] = merge(st[at * 2], st[at * 2 + 1]);
        }
        T query(int at, int tl, int tr, int l, int r){
            if (tl >= l && tr <= r){
                return st[at];
            }
            if (tl > r || tr < l){
                return NEUTER;
            }
            int tm = tl + (tr - tl) / 2;
            return merge(
                query(at * 2, tl, tm, l, r), 
                query(at * 2 + 1, tm + 1, tr, l, r)
            );
        }
    public:
        SegmentTree(int len) : len(len) {
            st = vector<T> (4*len, NEUTER);
        }
        SegmentTree(const vector<T> & arr) : len(arr.size()){
            st = vector<T> (4*len, NEUTER);
            build(arr, 1, 0, len-1);
        }
        void set(int ind, T val){
            update(1, 0, len-1, ind - 1, val);
        }
        T query(int l, int r){
            return query(1, 0, len-1, l-1, r-1);
        }
};
void solve(){
  int n, q; cin >> n >> q; 
  vector<ll> nums(n,0); for(auto & i:nums) cin>>i;
  SegmentTree<ll> st(nums);
  while (q--){
      int a, b; cin >> a >> b;
      cout << st.query(a, b) << endl;
  }
}

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int t = 1;
  while (t--) solve();
  return 0;
}
