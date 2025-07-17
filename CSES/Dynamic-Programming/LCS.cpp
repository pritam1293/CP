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
    int n,m;
    cin>>n>>m;
    vector<int> a(n), b(m);
    for(int i=0;i<n;i++) cin>>a[i];
    for(int i=0;i<m;i++) cin>>b[i];

    vector<vector<int>> dp(n+1, vector<int>(m+1));
    for(int i=1;i<=n;i++) {
        for(int j=1;j<=m;j++) {
            if(a[i-1] == b[j-1]) dp[i][j] = 1 + dp[i-1][j-1];
            else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        }
    }
    cout<<dp[n][m]<<endl;
    //printing the lcs
    int i = n, j = m;
    int idx = dp[n][m]-1;
    vector<int> ans(idx+1);
    while(i > 0 && j > 0) {
        if(a[i-1] == b[j-1]) {
            ans[idx] = a[i-1];
            i--;j--;idx--;
        }
        else if(dp[i-1][j] > dp[i][j-1]) i--;
        else j--;
    }
    for(auto& val : ans) {
        cout<<val<<" ";
    }
}