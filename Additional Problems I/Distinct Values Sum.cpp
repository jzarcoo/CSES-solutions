#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vll;
#define endl '\n'

const int N=2e5+5;

ll arr[N];

unordered_map<int, vector<int>> m;

int n;
int distintos;

void solve()
{
    ll ans = 0; 

    for(auto &[val, vec] : m)
    {
        int prev = 0;
        for(int p : vec)
        {
            ll valid =  1LL * (p - prev + 1) * (n - p);
            ans += valid;
            prev = p + 1;
        }

    }

    cout << ans<<endl;
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    cin>>n;
    vll a(n);
    for(int i=0; i<n; i++){
        cin>>a[i];
        arr[i] = a[i];
    }
    sort(a.begin(), a.end());
    a.erase(unique(a.begin(), a.end()), a.end());
    distintos = a.size();
    for(int i=0; i<n; i++){
        arr[i] = lower_bound(a.begin(), a.end(), arr[i]) - a.begin() + 1;
        m[arr[i]].push_back(i);
    }
    solve();
}
    

