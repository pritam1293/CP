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
    int n;
    cin>>n;
    vector<int> dp(n+1, 1e9);
    dp[0] = 0;
    for(int i=1;i<=n;i++) {
        int num = i;
        while(num) {
            int d = num % 10;
            dp[i] = min(dp[i], 1 + dp[i-d]);
            num /= 10;
        }
    }
    cout<<dp[n]<<endl;
}