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

void dfs(int node, int parent, vector<vector<int>> &dp, vector<vector<int>> &tree) {
    dp[0][node] = 0;
    for(auto& child : tree[node]) {
        if(child == parent) continue;
        dfs(child, node, dp, tree);
        dp[0][node] += max(dp[0][child], dp[1][child]);
        int diff = min(0, dp[0][child] - dp[1][child]);
        dp[1][node] = max(dp[1][node], diff);
    }
    dp[1][node] += dp[0][node] + 1;
}

void solve() {
    int n;
    cin>>n;
    vector<vector<int>> tree(n+1);
    for(int i=1;i<n;i++) {
        int u, v;
        cin>>u>>v;
        tree[u].push_back(v);
        tree[v].push_back(u);
    }
    vector<vector<int>> dp(2, vector<int>(n+1, -1e9));
    dfs(1, -1, dp, tree);
    cout<<max(dp[0][1], dp[1][1])<<endl;
}