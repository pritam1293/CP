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

// int rec(int i, int wt, vector<int> &w, vector<int> &v, vector<vector<int>> &dp) {
//     if(i == w.size()) return 0;
//     if(dp[i][wt] != -1) return dp[i][wt];
//     int ans = rec(i+1, wt, w, v, dp);
//     if(wt >= w[i]) ans = max(ans, v[i] + rec(i+1, wt-w[i], w, v, dp));
//     return dp[i][wt] = ans;
// }

void solve() {
    int n, wt;
    cin>>n>>wt;
    vector<int> w(n), v(n);
    for(int i = 0; i < n; i++) {
        cin>>w[i]>>v[i];
    }
    // vector<vector<int>> dp(n, vector<int>(wt+1, -1));
    // cout<<rec(0, wt, w, v, dp)<<endl;
    vector<vector<int>> dp(n+1, vector<int>(wt+1));
    for(int i = n-1; i >= 0; i--) {
        for(int k = 0 ; k <= wt; k++) {
            dp[i][k] = dp[i+1][k];
            if(k >= w[i]) dp[i][k] = max(dp[i][k], v[i] + dp[i+1][k-w[i]]);
        }
    }
    cout<<dp[0][wt]<<endl;
}