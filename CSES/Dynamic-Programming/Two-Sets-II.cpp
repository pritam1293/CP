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

void solve() {
    int n;
    cin>>n;
    int sum = n * (n+1)/2;
    if(sum % 2) {
        cout<<0<<endl;
        return;
    }
    sum /= 2;
    vector<vector<int>> dp(n, vector<int>(sum+1));
    dp[0][0] = 1;
    for(int i=1;i<n;i++) {
        for(int j=0;j<=sum;j++) {
            dp[i][j] = dp[i-1][j];
            if(j-i >= 0) {
                dp[i][j] = (dp[i][j] + dp[i-1][j-i]) % mod;
            }
        }
    }
    cout<<dp[n-1][sum]<<endl;
}