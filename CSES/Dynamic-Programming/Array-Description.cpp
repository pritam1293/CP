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

long long mod = 1e9 + 7;

void solve() {
    int n,m;
    cin>>n>>m;
    vector<int> a(n);
    for(int i=0;i<n;i++) {
        cin>>a[i];
    }
    vector<vector<long long>> dp(n, vector<long long>(m+2));
    if(a[0] == 0) {
        for(int i=1;i<=m;i++) dp[0][i] = 1;
    }
    else {
        dp[0][a[0]] = 1;
    }
    for(int i=1;i<n;i++) {
        if(a[i] == 0) {
            for(int j=1;j<=m;j++) {
                dp[i][j] = (dp[i-1][j-1] + dp[i-1][j] + dp[i-1][j+1]) % mod;
            }
        }
        else {
            dp[i][a[i]] = (dp[i-1][a[i]-1] + dp[i-1][a[i]] + dp[i-1][a[i]+1]) % mod;
        }
    }
    long long ans = 0;
    for(int i=1;i<=m;i++) {
        ans = (ans + dp[n-1][i]) % mod;
    }
    cout<<ans<<endl;
}