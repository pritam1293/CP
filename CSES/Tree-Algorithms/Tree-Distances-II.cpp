#include<bits/stdc++.h>
using namespace std;
#define int long long
void solve();
int32_t main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
#ifndef ONLINE_JUDGE
    freopen("../../input.txt", "r", stdin);
    freopen("../../output.txt", "w", stdout);
#endif
    int t=1;
    while(t--)  solve();
    cerr << "time: " << (float)clock() / CLOCKS_PER_SEC << endl; return 0;
}

vector<int> dp, ans;

void dfs1(int node, int parent, int len , vector<vector<int>> &tree) {
    ans[1] += len;
    dp[node] = 1;
    for(auto& child : tree[node]) {
        if(child == parent) continue;
        dfs1(child, node, len+1, tree);
        dp[node] += dp[child];
    }
}

void dfs2(int node, int parent, int n, vector<vector<int>> &tree) {
    for(auto& child : tree[node]) {
        if(child == parent) continue;
        ans[child] = ans[node] + n - 2 * dp[child];
        dfs2(child, node, n, tree);
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
    dp = vector<int>(n+1);
    ans = vector<int>(n+1);
    dfs1(1, -1, 0, tree);
    dfs2(1, -1, n, tree);
    for(int i=1;i<=n;i++) {
        cout<<ans[i]<<" ";
    }
}