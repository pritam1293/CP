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

// int rec(int n, int m, string &a, string &b) {
//     if(n == 0) return m;
//     if(m == 0) return m;

//     if(a[n-1] == b[m-1]) return rec(n-1, m-1, a, b);
//     else {
//         int del = 1 + rec(n-1, m, a, b);
//         int add = 1 + rec(n, m-1, a, b);
//         int rep = 1 + rec(n-1, m-1, a, b);
//         return min({del, add, rep});
//     }
// }

void solve() {
    string a,b;
    cin>>a>>b;
    int n = a.size() , m = b.size();
    vector<vector<int>> dp(n+1, vector<int>(m+1));
    for(int i=0;i<=n;i++) dp[i][0] = i;
    for(int j=0;j<=m;j++) dp[0][j] = j;
    for(int i=1;i<=n;i++) {
        for(int j=1;j<=m;j++) {
            if(a[i-1] == b[j-1]) dp[i][j] = dp[i-1][j-1];
            else {
                dp[i][j] = 1 + min({dp[i-1][j], dp[i][j-1], dp[i-1][j-1]});
            }
        }
    }
    cout<<dp[n][m]<<endl;
}