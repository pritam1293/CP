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

int bfs(int node,int n, vector<vector<int>> &tree) {
    queue<pair<int,int>> q;
    q.push({node, 0});
    vector<bool> vis(n+1, false);
    vis[node] = true;
    // int u = node
    while(!q.empty()) {
        node = q.front().first;
        int len = q.front().second;
        q.pop();
        for(auto& child : tree[node]) {
            if(!vis[child]) {
                vis[child] = true;
                q.push({child, len+1});
            }
        }
    }
    return node;
}

void dfs(int node, int parent, int dist, int i, vector<vector<int>> &dp, vector<vector<int>> &tree) {
    dp[i][node] = dist;
    for(auto& child : tree[node]) {
        if(child != parent) dfs(child, node, dist+1, i, dp, tree);
    }
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
    int node_start = bfs(1, n, tree);
    int node_end = bfs(node_start, n, tree);

    vector<vector<int>> dp(2, vector<int>(n+1));
    dfs(node_start, -1, 0, 0, dp, tree);
    dfs(node_end, -1, 0, 1, dp, tree);
    for(int i=1;i<=n;i++) {
        cout<<max(dp[0][i], dp[1][i])<<" ";
    }
}