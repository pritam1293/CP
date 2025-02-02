#include<bits/stdc++.h>
using namespace std;
#define int long long
void solve();
int32_t main() {
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

void solve() {
    int n;
    cin>>n;
    priority_queue<int,vector<int>,greater<int>> pq;
    vector<int> a(n);
    for(int i=0;i<n;i++) {
        cin>>a[i];
        pq.push(a[i]);
    }
    int val = 0;
    int ans = 0;

    while(!pq.empty()) {
        int top = pq.top();
        pq.pop();
        ans += max(0ll , top-val);
        val++;
    }
    cout<<ans<<endl;
}
