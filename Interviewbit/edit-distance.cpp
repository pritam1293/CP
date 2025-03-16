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

int rec(int n, int m, string &a, string &b, vector<vector<int>> &dp) {
    if(n == 0) return m;
    if(m == 0) return n;
    if(dp[n][m] == -1) {
        if(a[n-1] == b[m-1]) {
            dp[n][m] = rec(n-1, m-1, a, b, dp);
        }
        else {
            int del = 1 + rec(n-1, m, a, b, dp);
            int ins = 1 + rec(n, m-1, a, b, dp);
            int rep = 1 + rec(n-1, m-1, a, b, dp);

            dp[n][m] = min({del, ins, rep});
        }
    }
    return dp[n][m];  
}

int minDistance(string &a, string &b) {
    int n = a.size() , m = b.size();
    vector<vector<int>> dp(n+1, vector<int>(m+1, -1));
    return rec(n, m, a, b, dp);
    return dp[n][m];
}

/*
method-2 : Iterative way.....

int minDistance(string a, string b) {
    int n = a.size(), m = b.size();
    vector<vector<int>> dp(n+1, vector<int>(m+1));
    for(int i=0;i<=n;i++) dp[i][0] = i;
    for(int j=0;j<=m;j++) dp[0][j] = j;
    
    for(int i=1;i<=n;i++) {
        for(int j=1;j<=m;j++) {
            if(a[i-1] == b[j-1]) dp[i][j] = dp[i-1][j-1];
            else dp[i][j] = 1 + min({dp[i-1][j-1], dp[i][j-1], dp[i-1][j]});
        }
    }
    return dp[n][m];
}

*/

void solve() {
    string a = "aaa";
    string b = "aa";
    cout<<minDistance(a,b);
}