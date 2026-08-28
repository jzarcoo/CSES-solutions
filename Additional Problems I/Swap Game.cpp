#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

ll pows[10];

// 0*9^8 + 1*9^7 + 2*9^6 ... + 8*9^0
ll target = 0;

ll g = 0;

ll move(ll v, int p, int q)
{
    p = 8-p;
    q = 8-q;

    // digit
    ll dp = v / pows[p];
    dp %= 9;
    ll dq = v / pows[q];
    dq %= 9;
    ll r = v 
            - dp * pows[p]
            - dq * pows[q]
            + dq * pows[p]
            + dp * pows[q];
    return r;
}

ll solve()
{
    vector<bool> vis(pows[9], false);
    vis[g]  = true;
    queue<pair<ll,ll>> q;
    q.emplace(g, 0);

    while(!q.empty())
    {
        auto [v, d] = q.front(); q.pop();
        if(v==target) return d;
        for(int i=0; i<=7; i++)
        {
            if(i%3==2) continue;
            ll to = move(v, i, i+1);
            if(!vis[to])
            {
                q.emplace(to, d+1);
                vis[to] = true;
            }
        }
        for(int i=0; i<=5; i++)
        {
            ll to = move(v, i, i+3);
            if(!vis[to])
            {
                q.emplace(to, d+1);
                vis[to] = true;
            }
        }
    }

    return -1;
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);

    pows[0]=1;
    for(int i=1; i<=9; i++)
    {
        pows[i] = 9 * pows[i-1];
    }
    for(int i=0; i<=8; i++)
    {
        target += i * pows[8-i];
        int x; cin>>x;
        g += --x * pows[8-i];
    }
    cout <<    solve() <<'\n';
    return 0;
}



