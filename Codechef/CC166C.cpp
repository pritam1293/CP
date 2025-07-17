#include<bits/stdc++.h>
using namespace std;
void solve();
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int t=1;
    cin>>t;
    while(t--)  solve();
    cerr << "time: " << (float)clock() / CLOCKS_PER_SEC << endl; return 0;
}

void cycle(int n,vector<int> &v,vector<int> &a) {
    vector<bool> vis(n+1,false);
    for(int i=1;i<=n;i++) {
        if(!vis[i]) {
            int curr = i;
            int len = 0;

            while(!vis[curr]) {
                vis[curr] = true;
                len++;
                curr = a[curr-1];
            }
            v.push_back(len);
        }
    }
}

void solve() {
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++) {
        cin>>a[i];
    }
    vector<int> v;
    cycle(n,v,a);
    long long ans = 0;
    if(v.size() > 1) {
        priority_queue<int,vector<int>,greater<int>> pq;
        for(int len : v) {
            pq.push(len);
        }
        while(pq.size() > 1) {
            int cost1 = pq.top();
            pq.pop();
            int cost2 = pq.top();
            pq.pop();

            ans += (long long)(cost1 + cost2);
            pq.push(cost1 + cost2);
        }
    }
    cout<<ans<<endl;
}
