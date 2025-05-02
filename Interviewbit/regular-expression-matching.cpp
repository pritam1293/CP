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

bool rec(int i, int j, string &s, string &pat) {
    if(j == pat.size()) return i == s.size();
    if(i == s.size()) return false;

    if(j == pat.size()-1 || pat[j+1] != '*') {
        return ((s[i] == pat[j] || pat[j] == '.') && rec(i+1, j+1, s, pat));
    }

    if(rec(i, j+2, s, pat)) return true;

    while(i < s.size() && (s[i] == pat[j] || pat[j] == '.')) {
        if(rec(i+1, j+2, s, pat)) return true;
        i++;
    }
    return false;
}

bool isMatch(string &s, string &pat) {
    int n = s.size(), m = pat.size();
    vector<vector<int>> dp(n+1, vector<int>(m+1, false));

    dp[0][0] = true;
    for(int j=1;j<=m;j++) {
        if(pat[j-1] == '*') {
            dp[0][j] = dp[0][j-2];
        }
    }

    for(int i=1;i<=n;i++) {
        for(int j=1;j<=m;j++) {
            //case-1
            if(s[i-1] == pat[j-1] || pat[j-1] == '.') dp[i][j] = dp[i-1][j-1];

            //case-2
            else if(pat[j-1] == '*') {
                dp[i][j] = dp[i][j-2];
                //sub-case
                if(s[i-1] == pat[j-2] || pat[j-2] == '.') dp[i][j] |= dp[i-1][j];
            }
        }
    }
    return dp[n][m];
}

void solve() {
    string s = "aab";
    string pat = "c*a*b";
    cout<<(isMatch(s, pat) ? "Y" : "N")<<endl;
}