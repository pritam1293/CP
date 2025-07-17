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
    int n, k;
    cin>>n>>k;
    vector<int> a(n);
    for(int i=0;i<n;i++) {
        cin>>a[i];
    }
    int inf = LLONG_MAX;
    vector<int> dp(n, inf);
    dp[0] = 0;
    for(int i = 1; i < n; i++) {
        for(int j = max(0ll, i-k); j < i; j++) {
            dp[i] = min(dp[i], abs(a[i]-a[j]) + dp[j]);
        }
    }
    cout<<dp[n-1]<<endl;
}
