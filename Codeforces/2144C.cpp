#include<bits/stdc++.h>
using namespace std;
#define int long long
void solve();
int32_t main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
#ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
#endif
    int t=1;
    cin>>t;
    while(t--)  solve();
    cerr << "time: " << (float)clock() / CLOCKS_PER_SEC << endl; return 0;
}

int mod = 998244353;

void solve() {
    int n;
    cin>>n;
    vector<int> a(n), b(n);
    for(int i = 0; i < n; i++) {
        cin>>a[i];
    }
    for(int i = 0; i < n; i++) {
        cin>>b[i];
    }
    vector<vector<int>> dp(n, vector<int>(2));
    /*
    dp[i][0] = no. of ways up to i without swapping i
    dp[i][1] = no. of ways up to i with swapping i
    */
    //base
    dp[0][0] = 1;
    dp[0][1] = 1;
    for(int i = 1; i < n; i++) {
        // not swap i
        if(a[i] >= a[i-1] && b[i] >= b[i-1]) {
            dp[i][0] = (dp[i][0] + dp[i-1][0]) % mod;
        }
        if(a[i] >= b[i-1] && b[i] >= a[i-1]) {
            dp[i][0] = (dp[i][0] + dp[i-1][1]) % mod;
        }
        //swap i
        if(b[i] >= a[i-1] && a[i] >= b[i-1]) {
            dp[i][1] = (dp[i][1] + dp[i-1][0]) % mod;
        }
        if(b[i] >= b[i-1] && a[i] >= a[i-1]) {
            dp[i][1] = (dp[i][1] + dp[i-1][1]) % mod;
        }
    }
    cout<< (dp[n-1][0] + dp[n-1][1]) % mod <<endl;
}