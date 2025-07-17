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

int mod = 1e9 + 7;

// int rec(int row, int col , int n, vector<string> &grid, vector<vector<int>> &dp) {
//     if(row == n-1 && col == n-1) return 1;
//     if(row >= n || col >= n) return 0;
//     if(grid[row][col] == '*') return 0;

//     if(dp[row][col] == -1) {
//         dp[row][col] = (rec(row, col+1, n, grid, dp) + rec(row+1, col, n, grid, dp)) % mod;
//     }
//     return dp[row][col];
// }
 
void solve() {
    int n;
    cin>>n;
    vector<string> grid(n);
    for(int i=0;i<n;i++) {
        cin>>grid[i];
    }

    if(grid[0][0] == '*' || grid[n-1][n-1] == '*') {
        cout<<0<<endl;
        return;
    }

    // vector<vector<int>> dp(n, vector<int>(n, -1));
    // cout << rec(0, 0, n, grid, dp) << endl;

    vector<vector<int>> dp(n, vector<int>(n));
    dp[n-1][n-1] = 1;
    for(int i=n-1;i>=0;i--) {
        for(int j=n-1;j>=0;j--) {
            if(grid[i][j] == '*') continue;
            if(i+1 < n) dp[i][j] = (dp[i][j] + dp[i+1][j]) % mod;
            if(j+1 < n) dp[i][j] = (dp[i][j] + dp[i][j+1]) % mod;
        }
    }
    cout<<dp[0][0]<<endl;
}