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
    // cin>>t;
    while(t--)  solve();
    cerr << "time: " << (float)clock() / CLOCKS_PER_SEC << endl; return 0;
}

int minCost(vector<vector<int>> &a) {
    int n = a.size();
    vector<vector<int>> dp(n, vector<int>(3));
    dp[0][0] = a[0][0];
    dp[0][1] = a[0][1];
    dp[0][2] = a[0][2];

    for(int i=1;i<n;i++) {
        dp[i][0] = a[i][0] + min(dp[i-1][1], dp[i-1][2]);
        dp[i][1] = a[i][1] + min(dp[i-1][0], dp[i-1][2]);
        dp[i][2] = a[i][2] + min(dp[i-1][1], dp[i-1][0]);
    }

    return min({dp[n-1][0], dp[n-1][1], dp[n-1][2]});
}

void solve() {
    int n = 51;
    vector<vector<int>> a(n, vector<int>(3));
    for(int i=0;i<n;i++) {
        for(int j=0;j<3;j++) {
            cin>>a[i][j];
        }
    }
    cout<<minCost(a);
}