#include<bits/stdc++.h>
using namespace std;
struct I{
    int r,l,i;
    bool operator<(const I & o){
        if(o.l==l)return r>o.r;
        return l<o.l;
    }
};
struct BIT{
    int n;
    vector<int> arr, bit;
    BIT(int n):n(n), arr(n), bit(n+1){}
    void add(int i, int d){
        arr[i]+=d; // 0 indexado
        // bit 1-indexado
        for(++i; i<=n; i+=i&-i)
            bit[i]+=d;
    }
    int query(int i){
        int s = 0;
        for(++i; i; i-=i&-i)
            s+=bit[i];
        return s;
    }
    int query(int l, int r){
        if (r<l) return 0;
        return query(r) - (l ? query(l-1) : 0);
    }
    void clear(){
        fill(arr.begin(), arr.end(),0);
        fill(bit.begin(), bit.end(),0);
    }
};
vector<I> in;
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    
    int n;cin>>n;
    vector<int> contains(n);
    vector<int> iscontained(n);
    vector<int> v;
    for(int i=0; i<n; i++){
        int l,r; cin>>l>>r;
        in.push_back({r,l,i});
        v.push_back(r);
    }
    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());
    auto id = [&](int i){
        return lower_bound(v.begin(), v.end(), i) - v.begin();
    };
    int len = v.size();
    sort(in.begin(),in.end());
    BIT tree(len);
    for(auto &[r, l, i] : in){
        iscontained[i] = tree.query(id(r), len-1);
        tree.add(id(r), 1);
    }
    tree.clear();
    for(auto it = in.rbegin(); it!=in.rend(); it++){
        auto [r,l,i] = *it;
        contains[i] = tree.query(id(r));
        tree.add(id(r), 1);
    }
    for(auto b:contains){
        cout<<b<<' ';
    }
    cout<<'\n';
    for(auto b:iscontained){
        cout<<b<<' ';
    }
}
