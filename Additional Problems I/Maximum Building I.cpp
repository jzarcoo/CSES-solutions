#include<bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n, m, ans=0; cin>>n>>m;
    vector<int> ant(m), h(m);
    for(int r=0; r<n; r++){
        stack<int> s;
        for(int c=0; c<m; c++){
            char x; cin>>x;
            h[c] = x=='.';
            if(r && h[c])
                h[c] += ant[c];
            while(!s.empty() && h[s.top()] >= h[c]){
                int t = s.top(); s.pop();
                int w = c;
                if(!s.empty())
                    w = w - s.top() - 1;
                ans = max(ans, h[t]*w);
            }
            s.push(c);
        }        
        while(!s.empty()){
            int t = s.top(); s.pop();
            int w = m;
            if(!s.empty())
                w = w - s.top() - 1;
            ans = max(ans, h[t] * w);
        }
        swap(ant, h);
        fill(h.begin(), h.end(), 0);
    }
    cout<<ans<<'\n';
}
