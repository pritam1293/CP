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

bool rec(int i, int j, string &s, string &p, vector<vector<int>> &dp) {
    if(i < 0 && j < 0) return true;
    if(j < 0 && i >= 0) return false;
    if(i < 0 && j >= 0) {
        for(int idx = j; idx <= j; idx++) {
            if(p[idx] != '*') return false;
        }
        return true;
    }

    if(dp[i][j] != -1) return dp[i][j];
    if(s[i] == p[j] || p[j] == '?') {
        return dp[i][j] = rec(i-1, j-1, s, p, dp);
    }
    if(p[j] == '*') {
        return dp[i][j] = (rec(i-1, j, s, p, dp) | rec(i, j-1, s, p, dp));
    }
    return dp[i][j] = false;
}

bool isMatch(string s, string p) {
    int n = p.size(), m = s.size();
    vector<vector<bool>> dp(n+1, vector<bool>(m+1, false));
    dp[0][0] = true;
    
    for(int j=1;j<=m;j++) {
        dp[0][j] = false;
    }
    
    for(int i=1;i<=n;i++) {
        bool flag = true;
        for(int j=1;j<=i;j++) {
            if(p[j-1] != '*') {
                flag = false;
                break;
            }
        }
        dp[i][0] = flag;
    }
    
    for(int i=1;i<=n;i++) {
        for(int j=1;j<=m;j++) {
            if(p[i-1] == s[j-1] || p[i-1] == '?') {
                dp[i][j] = dp[i-1][j-1];
            }
            else if(p[i-1] == '*') {
                dp[i][j] = (dp[i-1][j] | dp[i][j-1]);
            }
            else dp[i][j] = false;
        }
    }
    return dp[n][m];
}

void solve() {
    string s,p;
    cin>>s>>p;
    cout<< (isMatch(s,p) ? "Yes" : "No") <<endl;
}