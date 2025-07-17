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
    cin>>t;
    while(t--)  solve();
    cerr << "time: " << (float)clock() / CLOCKS_PER_SEC << endl; return 0;
}

void solve() {
    int n;
    string s;
    cin>>n>>s;
    vector<vector<int>> dp(n+1, vector<int>(2));
    //dp[i][0] = min flips req to make all 0s till ith bit
    //dp[i][1] = min flips req to make 1 ith bit

    dp[0][0] = (s[0] == '1');
    dp[0][1] = (s[0] == '0');

    for (int i=1;i<n;i++) {
        dp[i][0] = dp[i-1][0] + (s[i] == '1');
        dp[i][1] = min(dp[i-1][0], dp[i-1][1]) + (s[i] == '0');
    }
    int ans = n;
    for (int i=0;i<n;i++){
        ans = min(ans, dp[i][1] + dp[n-1][0] - dp[i][0]);
    }
    cout<< min(ans, dp[n-1][0]) <<endl;
}