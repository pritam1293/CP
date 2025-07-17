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
    while(t--)  solve();
    cerr << "time: " << (float)clock() / CLOCKS_PER_SEC << endl; return 0;
}

void solve() {
    int n;
    cin>>n;
    vector<int> a(n);
    int mx = 0;
    for(int i=0;i<n;i++) {
        cin>>a[i];
        mx = max(mx, a[i]);
        // cout<<a[i]<<" ";
    }
    vector<int> dp(mx+1), cnt(mx+1);
    for(auto& val : a) cnt[val]++;
    dp[1] = cnt[1];
    for(int i=2;i<=mx;i++) {
        dp[i] = max(dp[i-1], dp[i-2] + i*cnt[i]);
    }
    cout<<dp[mx]<<endl;
}