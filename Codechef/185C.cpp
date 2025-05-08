#include<bits/stdc++.h>
using namespace std;
#define int long long
void solve();
int32_t main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
#ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
#endif
    int t=1;
    cin>>t;
    while(t--)  solve();
    cerr << "time: " << (float)clock() / CLOCKS_PER_SEC << endl; return 0;
}

void solve() {
    int n;
    cin>>n;
    n *= 2;
    vector<int> a(n);
    for(int i=0;i<n;i++) {
        cin>>a[i];
    }
    priority_queue<int> pq;
    int ans = 0;
    for(int i = n-1; i >=1 ; i -= 2) {
        pq.push(a[i]);
        pq.push(a[i-1]);
        ans += pq.top();
        pq.pop();
    }
    cout<<ans<<endl;
}