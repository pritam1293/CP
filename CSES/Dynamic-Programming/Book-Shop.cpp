#include<bits/stdc++.h>
using namespace std;
void solve();
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
#ifndef ONLINE_JUDGE
    freopen("../../input.txt", "r", stdin);
    freopen("../../output.txt", "w", stdout);
#endif
    int t=1;
    while(t--)  solve();
    cerr << "time: " << (float)clock() / CLOCKS_PER_SEC << endl; return 0;
}

// int rec(int money, int i, vector<int> &c, vector<int> &p, vector<vector<int>> &dp) {
//     if(i == c.size()) return 0;
//     if(dp[money][i] == -1) {
//         int ans = 0 + rec(money, i+1, c, p, dp);// not take
//         if(money - c[i] >= 0) {
//             ans = max(ans, p[i] + rec(money - c[i], i+1, c, p, dp));// take
//         }
//         dp[money][i] = ans;
//     }
//     return dp[money][i];
// }

void solve() {
    int n, money;
    cin>>n>>money;
    vector<int> c(n), p(n);
    for(int i=0;i<n;i++) {
        cin>>c[i];
    }
    for(int i=0;i<n;i++) {
        cin>>p[i];
    }
    // vector<vector<int>> dp(money+1, vector<int>(n, -1));
    // cout<<rec(money, 0, c, p, dp)<<endl;

    // vector<vector<int>> dp(money+1, vector<int>(n));
    // vector<int> before(money+1);
    // vector<int> after(money+1);
    // for(int i=1;i<=money;i++) {
    //     for(int j=n-1;j>=0;j--) {
    //         if(j+1 < n) {
    //             dp[i][j] = dp[i][j+1];
    //             if(i - c[j] >= 0) dp[i][j] = max(dp[i][j], p[j] + dp[i - c[j]][j+1]);
    //         }
    //     }
    // }
    // cout<<dp[money][0]<<endl;

    vector<int> dp(money+1);
    for(int i=0;i<n;i++) {
        for(int cost = money; cost > 0; cost--) {
            if(cost < c[i]) continue;
            dp[cost] = max(dp[cost], p[i] + dp[cost - c[i]]);
        }
    }
    cout<<dp[money]<<endl;
}