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
    while(t--)  solve();
    cerr << "time: " << (float)clock() / CLOCKS_PER_SEC << endl; return 0;
}

// int profit(vector<int> &a) {
//     int n = a.size();
//     vector<vector<int>> dp(n+1, vector<int>(2));
//     if(i == a.size()) return 0;
//     if(dp[i][buy] != -1) return dp[i][buy]; 
//     int ans = 0;
//     if(buy) {
//         ans = max(-a[i] + profit(i+1, a, 0, dp), profit(i+1, a, 1, dp));
//     }
//     else{
//         ans = max(a[i] + profit(i+1, a, 1, dp), profit(i+1, a, 0, dp));
//     }
//     return dp[i][buy] = ans;
// }

void solve() {
    vector<int> a = {1,2,3,4,5};
    int n = a.size();
    vector<vector<int>> dp(n+1, vector<int>(2));
    for(int i=n-1;i>=0;i--) {
        for(int buy=0;buy<=1;buy++) {
            int profit = 0;
            
            if(buy) {
                profit = max(-a[i] + dp[i+1][0], dp[i+1][1]);
            }
            else{
                profit = max(a[i] + dp[i+1][1], dp[i+1][0]);
            }

            dp[i][buy] = profit;
        }
    }
    cout<<dp[0][1]<<endl;
}
