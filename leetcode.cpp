#include<bits/stdc++.h>
using namespace std;
void solve();
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int t=1;
    while(t--)  solve();
    cerr << "time: " << (float)clock() / CLOCKS_PER_SEC << endl; return 0;
}

void solve() {
    vector<int> a = {331,307,121,266,397,451,279,305};
    int k = 4;
    // cout<<minXor(a, k)<<endl;
    int n = a.size();
    int inf = INT_MAX;
    vector<int> prefix(n+1);
    for(int i = 0; i < n; i++) {
        prefix[i+1] = (a[i] ^ prefix[i]);
    }
    vector<vector<int>> dp(n+1, vector<int>(k+1, inf));
    /*dp[i][j] = min xor val of max xor after using first i
                 elements and forming j subarrays
    */
    dp[0][0] = 0;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= k; j++) {
            for(int l = 0; l < i; l++) {
                if(dp[l][j-1] != inf) {
                    int curr = (prefix[i] ^ prefix[l]);
                    dp[i][j] = min(dp[i][j], max(dp[l][j-1], curr));
                }
            }
        }
    }
    cout<<dp[n][k]<<endl;
}
    