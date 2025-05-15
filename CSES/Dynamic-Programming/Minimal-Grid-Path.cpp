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

void rec(int row, int col, int n, vector<string> &grid, string &ans) {
    if(row >= n || col >= n) return ;
} 

void solve() {
    int n;
    cin>>n;
    vector<string> grid(n);
    for(int i=0;i<n;i++) cin>>grid[i];
    string ans;
    rec(0, 0, n, grid, ans);
    cout<<ans<<endl;
}