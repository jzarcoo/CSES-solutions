#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

#define sz(z) (int) z.size()
#define pb push_back
#define all(z) z.begin(), z.end()
#define mid(l, r) (l) + ((r) - (l)) /2

int n, q, distinct;
vector<int> v, arr;

struct Node{
    Node *l, *r;
    ll sum;
    Node(ll val) :
        sum(val)
    {
        
    }
    Node(Node *l, Node *r) :
        l(l),
        r(r),
        sum(0LL)
    {
        if(l){
            sum += l->sum;
        }
        if(r){
            sum += r->sum;
        }
    }

};

// persistent
int mini, maxi;
vector<Node*> roots;

Node* build(int tl, int tr){
    if(tl == tr){
        return new Node(0LL);
    }
    int tm = mid(tl,tr);
    return new Node(
        build(tl, tm),
        build(tm+1,tr)
    );
}

Node* update(Node* u, int tl, int tr, int pos, ll val){
    if(tl == tr){
        return new Node(u->sum + val);
    }
    int tm = mid(tl, tr);
    if(pos <= tm){
        return new Node(
            update(u->l, tl, tm, pos, val),
            u->r
        );
    }else{
        return new Node(
            u->l,
            update(u->r, tm+1, tr, pos, val)
        );
    }
}

ll cnt(Node* u, int tl, int tr, int pos){
    if (tr <= pos){
        return u->sum;
    }
    int tm = mid(tl, tr);
    if(pos <= tm){
        return cnt(u->l, tl, tm, pos);
    }
    return u->l->sum
        + cnt(u->r, tm+1, tr, pos);
}

map<ll, int> cache;

ll solve(int ql, int qr){
    ll ans = 1;
    do{
        int x;
        if(cache.count(ans) == 0){
            auto it = upper_bound(all(v), ans);
            if(it == v.begin()) break;
            --it;
            x = it - v.begin() + 1;
            cache[ans] = x;
        }else{
            x = cache[ans];
        }

        // values that are less than or equal to ans
        ll b = cnt(roots[qr], mini, maxi, x);
        ll a = cnt(roots[ql-1], mini, maxi, x);
        if (b-a < ans) break;
        ans = b - a + 1;
    }while(true);
    return ans;
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin>>n>>q;
    for(int i=0; i<n; i++){
        int x; cin>>x;
        arr.push_back(x);
        v.push_back(x);
    }
    sort(all(v));
    v.erase(unique(all(v)), v.end());

    distinct = sz(v);
    mini = 0, maxi = distinct + 1;
    
    roots.push_back(build(mini, maxi));

    for(int i=0; i<n; i++){
        ll x = arr[i];
        int pos = lower_bound(all(v), x) - v.begin() + 1;        
        roots.push_back(update(roots.back(), mini, maxi, pos, x));
    }

    while(q--){
            int ql, qr; cin>>ql>>qr;
            cout << solve(ql, qr) << '\n'; 
       }
}

