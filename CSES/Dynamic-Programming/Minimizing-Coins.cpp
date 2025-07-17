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
    int n, sum;
    cin>>n>>sum;
    vector<int> a(n);
    for(int i=0;i<n;i++) {
        cin>>a[i];
    }
    vector<int> dp(sum+1, INT_MAX);
    dp[0] = 0;
    for(int i=1;i<=sum;i++) {
        for(int j=0;j<n;j++) {
            if(a[j] > i || dp[i-a[j]] == INT_MAX) continue;
            dp[i] = min(dp[i], dp[i-a[j]] + 1);
        }
    }
    cout<<(dp[sum] == INT_MAX ? -1 : dp[sum])<<endl;
}