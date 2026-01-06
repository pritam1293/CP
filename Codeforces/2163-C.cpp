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

struct pair {
    int mx;
    int mn;
};

void solve() {
    int n;
    cin>>n;
    vector<vector<int>> grid(2, vector<int>(n));
    for(int i = 0; i < 2; i++) {
        for(int j = 0; j < n; j++) {
            cin>>grid[i][j];
        }
    }
    vector<pair> prefix(n), suffix(n);
    prefix[0].mn = grid[0][0];
    prefix[0].mx = grid[0][0];
    for(int i = 1; i < n; i++) {
        prefix[i].mn = min(prefix[i-1].mn, grid[0][i]);
        prefix[i].mx = max(prefix[i-1].mx, grid[0][i]);
    }
    suffix[n-1].mn = gird[1][n-1];
    suffix[n-1].mx = gird[1][n-1];
    for(int i = n-2; i >= 0; i--) {
        suffix[i].mn = min(suffix[i+1].mn, grid[1][i]);
        suffix[i].mx = max(suffix[i+1].mx, grid[1][i]);
    }
    int left_min = 1e9, left_max = 
}