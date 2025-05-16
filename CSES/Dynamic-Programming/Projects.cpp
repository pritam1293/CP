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

int rec(int i, int days, vector<vector<int>> &a, map<pair<int,int>, int> &dp) {
    if(i == a.size()) return 0;
    if(dp.find({i, days}) == dp.end()) {
        int money = rec(i+1, days, a, dp);
        if(a[i][0] >= days) {
            money = max(money, a[i][2] + rec(i+1, a[i][1] + 1, a, dp));
        }
        dp[{i, days}] = money;
    }
    return dp[{i, days}];
}

void solve() {
    int n;
    cin>>n;
    vector<vector<int>> a(n, vector<int>(3));
    for(int i=0;i<n;i++) {
        for(int j=0;j<3;j++) {
            cin>>a[i][j];
        }
    }
    map<pair<int,int>, int> dp;
    cout<<rec(0, 0, a, dp)<<endl;
}