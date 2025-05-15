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

void solve() {
    int n, m;
    cin>>n>>m;
    vector<vector<int>> dp(n+1, vector<int>(m+1, 1e9));
    for(int i=0;i<=n;i++) {
        for(int j=0;j<=m;j++) {
            if(i == j) dp[i][j] = 0;
            else {
                //j
                for(int k=1;k<j;k++) {
                    dp[i][j] = min(dp[i][j], 1 + dp[i][k] + dp[i][j-k]);
                }
                //i
                for(int k=1;k<i;k++) {
                    dp[i][j] = min(dp[i][j], 1 + dp[k][j] + dp[i-k][j]);
                }
            }
        }
    }
    cout<<dp[n][m]<<endl;
}