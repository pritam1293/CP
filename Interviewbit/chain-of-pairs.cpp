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
    // cin>>t;
    while(t--)  solve();
    cerr << "time: " << (float)clock() / CLOCKS_PER_SEC << endl; return 0;
}

int rec(int curr, int prev, vector<vector<int>> &a, vector<vector<int>> &dp) {
    if(curr == a.size()) return 0;

    if(dp[curr][prev+1] != -1) return dp[curr][prev+1];

    int len = rec(curr+1, prev, a, dp);
    if(prev == -1 || a[prev][0] > a[curr][1]) {
        len = max(len, rec(curr+1, curr, a, dp));
    }

    return dp[curr][prev+1] = len;
}

int solve(vector<vector<int> > &a) {
    int n = a.size();
    vector<int> dp(n, 1);
    int ans = 1;
    for(int i=1;i<n;i++) {
        for(int j=0;j<i;j++) {
            if(a[i][0] > a[j][1]) {
                dp[i] = max(dp[i], 1 + dp[j]);
                ans = max(ans, dp[i]);
            }
        }
    }
    return ans;
}


void solve() {
    int n;
    cin>>n;
    vector<vector<int>> a(n,vector<int>(2));
    for(int i=0;i<n;i++) {
        cin>>a[i][0]>>a[i][1];
    }
    cout<<solve(a)<<endl;
}