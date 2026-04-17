#include<bits/stdc++.h>
using namespace std;
#define S second
#define F first
#define endl '\n'
#define sz(z) (int)z.size()
#define print(v) for(int x:v){cout<<x<<' ';}cout<<endl
struct ST{
    vector<int> st;
    int n;
    int NEUTER = INT_MIN;
    ST(int len){
        n = 1;
        while (n < len) n<<=1;
        st.assign(2*n, 0);
    }
    int query(int l, int r){
        if(r<l) return NEUTER;
        int ans = NEUTER;
        for(l+=n, r+=n; l<=r; l/=2, r/=2){
            if(l&1) ans = max(ans, st[l++]);
            if(!(r&1)) ans = max(ans, st[r--]);
        }
        return ans;
    }
    void update(int p, int v){
        for(st[p+=n]=v;p>1;p/=2)
            st[p/2] = max(st[p], st[p^1]);
    }
};
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n; cin>>n;
    vector<int> height(n); for(auto &i: height) cin>>i;
    vector<int> l(n, -1), r(n, -1);
    stack<int> st;
    for (int i = 0; i < n; i++) {
        while (!st.empty() && height[st.top()] <= height[i]) {
            int tp = st.top(); st.pop();
        }
        if (!st.empty()) {
            l[i] = st.top();
        } else {
            l[i] = -1;
        }
        st.push(i);
    }
    stack<int> str;
    for (int i = n - 1; i >= 0; i--){
        while(!str.empty() && height[str.top()] <= height[i]) {
            int tp = str.top(); str.pop();            
        }
        if (!str.empty()) {
            r[i] = str.top();
        } else {
            r[i] = n;
        }
        str.push(i);        
    }
    // print(l);
    // print(r);
    vector<pair<int, int>> v;
    for (int i = 0; i < n; i++) {
        v.emplace_back(height[i], i);
    }
    sort(v.begin(), v.end());
    ST t(n);
    for (int s = 0; s < n; ){
        int e = s;
        while (e+1 < n && v[e + 1].F == v[s].F) e++;
        vector<pair<int,int>> calc;
        for (int i=s; i<=e; i++){
            int id = v[i].S;
            int start = l[id] + 1,
                end = r[id] - 1;
            //cout << id << ' '<<start<<' '<<end<<endl;
            int ans = 1 + t.query(start, end);
            calc.emplace_back(ans, id);
        }
        for(auto &[val, id] : calc){
            t.update(id, val);
        }
        s = e + 1;
    }
    cout << t.query(0, n-1) << '\n';
}
