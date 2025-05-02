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
    while(t--)  solve();
    cerr << "time: " << (float)clock() / CLOCKS_PER_SEC << endl; return 0;
}

// bool rec(int i, int j, int k, string &a, string &b, string &c) {
//     if(i == a.size() && j == b.size()) return k == c.size();
//     if(k == c.size()) return false;
    
//     bool cond1 = false, cond2 = false;

//     if(i < a.size() && a[i] == c[k]) {
//         cond1 = rec(i+1, j, k+1, a, b, c);
//     }
//     if(j < b.size() && b[j] == c[k]) {
//         cond2 = rec(i, j+1, k+1, a, b, c);
//     }

//     return (cond1 | cond2);
// }

bool isInterleave(string &a, string &b, string &c) {
    if(a.size() + b.size() != c.size()) return 0;

    int n = a.size(), m = b.size();
    vector<vector<bool>> dp(n+1, vector<bool>(m+1));
    dp[0][0] = true;
    for(int j=1;j<=m;j++) {
        if(c[j-1] == b[j-1]) dp[0][j] = dp[0][j-1];
    }
    for(int i=1;i<=n;i++) {
        if(c[i-1] == a[i-1]) dp[i][0] = dp[i-1][0];
    }

    for(int i=1;i<=n;i++) {
        for(int j=1;j<=m;j++) {
            int k = i+j-1;
            bool cond1 = (a[i-1] == c[k] ? dp[i-1][j] : false);
            bool cond2 = (b[j-1] == c[k] ? dp[i][j-1] : false);
            dp[i][j] = (cond1 | cond2);
        }
    }

    return dp[n][m];
}

void solve() {
    string a = "aabcc";
    string b = "dbbca";
    string c = "aadbbcbcac";
    //a+b = c
    cout<< (isInterleave(a, b, c) ? "Y" : "N") <<endl;
}
