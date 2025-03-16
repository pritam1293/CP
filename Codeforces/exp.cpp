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

int maxSum(vector<vector<int>> &a) {
    int n = a[0].size();
    vector<int> dp(n);
    int ans = 0;
    for(int i=0;i<n;i++) {
        if(i-2 >= 0) {
            dp[i] = max(a[0][i] , a[1][i]) + dp[i-2];
            if(i-3 >= 0) {
                dp[i] = max(dp[i] , max(a[0][i] , a[1][i]) + dp[i-3]);
            }
        }
        else{
            dp[i] = max(a[0][i] , a[1][i]);
        }

        ans = max(ans, dp[i]);
    }
    // int ans = 0;
    // for(int i=0;i<n;i++) {
    //     ans = max(ans, dp[i]);
    // }
    return ans;
}

void solve() {
    vector<vector<int>> a = {{16, 5, 54, 55, 36, 82, 61, 77, 66, 61},
                             {31, 30, 36, 70, 9, 37, 1, 11, 68, 14}};
    cout<<maxSum(a)<<endl;
}
