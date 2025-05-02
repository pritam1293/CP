#include<bits/stdc++.h>
using namespace std;
void solve();
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
#ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
#endif
    int t=1;
    while(t--)  solve();
    cerr << "time: " << (float)clock() / CLOCKS_PER_SEC << endl; return 0;
}

int minPathSum(vector<vector<int>> &grid) {
    int n = grid.size();
    int m = grid[0].size();
    vector<vector<int>> dp(n, vector<int>(m));
    dp[n-1][m-1] = grid[n-1][m-1];

    for(int j=m-2;j>=0;j--) {
        dp[n-1][j] = grid[n-1][j] + dp[n-1][j+1];
    }
    for(int i=n-2;i>=0;i--) {
        dp[i][m-1] = grid[i][m-1] + dp[i+1][m-1];
    }

    for(int i=n-2;i>=0;i--) {
        for(int j=m-2;j>=0;j--) {
            dp[i][j] = grid[i][j] + min(dp[i+1][j], dp[i][j+1]);
        }
    }
    return dp[0][0];
}

void solve() {
    vector<vector<int>> grid = {{1,3,2}, {4,3,1}, {5,6,1}};
    cout<<minPathSum(grid)<<endl;
}