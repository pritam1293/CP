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

void solve() {
    int n;
    cin>>n;
    vector<int> a(n), b(n), c(n);
    for(int i = 0; i < n; i++) {
        cin>>a[i]>>b[i]>>c[i];
    }
    vector<vector<int>> dp(3, vector<int>(n+1));
    for(int i = 1; i <= n; i++) {
        dp[0][i] = a[i-1] + max(dp[1][i-1], dp[2][i-1]);
        dp[1][i] = b[i-1] + max(dp[0][i-1], dp[2][i-1]);
        dp[2][i] = c[i-1] + max(dp[1][i-1], dp[0][i-1]);
        // cout<<dp[0][i]<<" "<<dp[1][i]<<" "<<dp[2][i]<<endl;
    }
    cout<<max({dp[0][n], dp[1][n], dp[2][n]})<<endl;
}