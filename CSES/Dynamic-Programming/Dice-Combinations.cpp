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
    vector<int> dp(n+6);//dp[i] = number of ways to get the sum i
    dp[1] = 1<<0;
    dp[2] = 1<<1;
    dp[3] = 1<<2;
    dp[4] = 1<<3;
    dp[5] = 1<<4;
    dp[6] = 1<<5;
    for(int i=7;i<=n;i++) {
        int sum = 0;
        for(int k=1;k<=6;k++) {
            sum = (sum % mod + dp[i-k] % mod) % mod;
        }
        dp[i] = sum;
    }
    cout<<dp[n]<<endl;
}