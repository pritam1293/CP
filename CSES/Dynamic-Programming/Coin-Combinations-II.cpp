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
    int n, sum;
    cin>>n>>sum;
    vector<int> a(n);
    for(int i=0;i<n;i++) {
        cin>>a[i];
    }
    vector<int> dp(sum+1);
    dp[0] = 1;
    for(int i=0;i<n;i++) {
        for(int j=a[i];j<=sum;j++) {
            dp[j] += dp[j-a[i]];
            if(dp[j] >= mod) dp[j] -= mod;
        }
    }
    cout<<dp[sum]<<endl;
}