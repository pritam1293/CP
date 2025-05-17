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

long long rec(int i, int j, vector<long long> &a, vector<vector<long long>> &dp) {
    if(i > j) return 0;
    if(dp[i][j] == -1) {
        long long op1 = a[i] + min(rec(i+2, j, a, dp), rec(i+1, j-1, a, dp));
        long long op2 = a[j] + min(rec(i, j-2, a, dp), rec(i+1, j-1, a, dp));

        dp[i][j] = max(op1, op2);
    }
    return dp[i][j];
}

void solve() {
    int n;
    cin>>n;
    vector<long long> a(n);
    for(int i=0;i<n;i++) {
        cin>>a[i];
    }
    int i = 0, j = n-1;
    while(a[i] == 0 && a[j] == 0) {
        i++;
        j--;
    }
    vector<vector<long long>> dp1(n, vector<long long>(n, -1));
    cout<<rec(i, j, a, dp1)<<endl;
}