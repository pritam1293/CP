#include<bits/stdc++.h>
using namespace std;
#define int long long
void solve();
int32_t main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
#ifndef ONLINE_JUDGE
    freopen("../../input.txt", "r", stdin);
    freopen("../../output.txt", "w", stdout);
#endif
    int t=1;
    while(t--)  solve();
    cerr << "time: " << (float)clock() / CLOCKS_PER_SEC << endl; return 0;
}

void solve() {
    int n, q;
    cin>>n>>q;
    vector<string> grid(n);
    for(int i = 0; i < n; i++) {
        cin>>grid[i];
    }
    vector<vector<int>> dp(n+1, vector<int>(n+1));
    for(int i = 1; i <= n; i++) {//row same
        for(int j = 1; j <= n; j++) {
            dp[i][j] = dp[i][j-1] + dp[i-1][j] - dp[i-1][j-1] + (grid[i-1][j-1] == '*');
        }
    }
    // for(auto& a : dp) {
    //     for(auto& e : a) {
    //         cout<<e<<" ";
    //     }
    //     cout<<endl;
    // }
    while(q--) {
        int y1, x1, y2, x2;
        cin>>y1>>x1>>y2>>x2;
        cout<<dp[y2][x2] - dp[y2][x1 - 1] - dp[y1 - 1][x2] + dp[y1 - 1][x1 - 1]<<endl;
    }
}