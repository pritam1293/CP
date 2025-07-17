#include<bits/stdc++.h>
using namespace std;
#define int long long
void solve();
int32_t main() {
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

void generateNextMask(int n, int mask, int newMask, int j, vector<int> &nextMask) {
    if(j == n) {
        nextMask.push_back(newMask);
        return;
    }

    if(j+1 < n && (((1 << j) & (mask)) == 0) && (((1 << (j+1)) & (mask)) == 0)) {
        generateNextMask(n, mask, newMask, j+2, nextMask);
    }
    if((((1 << j) & (mask)) == 0)) {
        generateNextMask(n, mask, newMask + (1 << j), j+1, nextMask);
    }
    if((((1 << j) & (mask)) != 0)) {
        generateNextMask(n, mask, newMask, j+1, nextMask);
    }
}

int rec(int n, int m, int i, int mask, vector<vector<int>> &dp) {
    if(i == m) {
        if(mask == 0) return 1;
        return 0;
    }
    if(dp[i][mask] != -1) return dp[i][mask];

    vector<int> nextMask;
    generateNextMask(n, mask, 0, 0, nextMask);

    int ans = 0;
    for(auto& x : nextMask) {
        ans = (ans + rec(n, m, i+1, x, dp)) % mod;
    }
    return dp[i][mask] = ans;
}

void solve() {
    int n, m;
    cin>>n>>m;
    vector<vector<int>> dp(1025, vector<int>(1025, -1));
    cout<<rec(n, m, 0, 0, dp)<<endl;
}