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

vector<int> uglyNumbers(int a, int b, int c, int n) {
    vector<int> dp(n+1);
    dp[0] = 1;
    int pa = 0, pb= 0, pc = 0;
    for(int i=1;i<=n;i++) {
        int a_multi = a * dp[pa];
        int b_multi = b * dp[pb];
        int c_multi = c * dp[pc];

        dp[i] = min({a_multi, b_multi, c_multi});

        if(dp[i] == a_multi) pa++;
        if(dp[i] == b_multi) pb++;
        if(dp[i] == c_multi) pc++;
    }
    dp.erase(dp.begin());
    return dp;
}

void solve() {
    for(int val : uglyNumbers(2,3,5,5)) {
        cout<<val<<" ";
    }
}