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
    // cin>>t;
    while(t--)  solve();
    cerr << "time: " << (float)clock() / CLOCKS_PER_SEC << endl; return 0;
}

int count(int n, int m, string &a, string &b, vector<vector<int>> &dp) {
    if(m == 0) return 1;
    if(n == 0) return 0;

    if(dp[n][m] == -1) {
        if(a[n-1] == b[m-1]) {
            dp[n][m] = count(n-1, m-1, a, b, dp) + count(n-1, m, a, b, dp);
        }
        else {
            dp[n][m] = count(n-1, m, a, b, dp);
        }
    }
    return dp[n][m];
}

void solve() {
    string a;
    string b;
    cin>>a>>b;
    int n = a.size() , m = b.size();
    vector<vector<int>> dp(n+1, vector<int>(m+1, -1));
    cout<<count(n,m,a,b,dp);
}
