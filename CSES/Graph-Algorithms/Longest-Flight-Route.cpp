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

void dfs(int node, vector<bool> &vis, vector<int> &dp, vector<vector<int>> &graph) {
    vis[node] = true;
    for(auto& child : graph[node]) {
        if(!vis[child]) dfs(child, vis, dp, graph);
        dp[node] = max(dp[node], 1 + dp[child]);
    }
}

void solve() {
    int n, m;
    cin>>n>>m;

    vector<vector<int>> graph(n+1);
    for(int i=0;i<m;i++) {
        int u,v;
        cin>>u>>v;
        graph[u].push_back(v);
    }
    vector<int> dp(n+1);
    vector<bool> vis(n+1, false);
    for(int i=1;i<=n;i++) {
        if(!vis[i]) {
            dfs(i, vis, dp, graph);
        }
    }
    int ans = 0;
    for(int i=1;i<=n;i++) {
        ans = max(ans, dp[i]);
    }
    // cout<<dp[n]<<endl;
    cout<<ans<<endl;
}