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

vector<vector<int>> tree, jump;
vector<int> depth, dp;

void dfs(int node, int p) {
    depth[node] = depth[p] + 1;
    jump[node][0] = p;
    for(auto& child : tree[node]) {
        if(child != p) {
            dfs(child, node);
        }
    }
}

int lca(int u, int v) {
    if(depth[u] > depth[v]) swap(u, v);
    int diff = depth[v] - depth[u];
    for(int i = 0; i < 21; i++) {
        if(1 & (diff >> i)) v = jump[v][i];
    }
    if(u == v) return u;
    for(int i = 20; i >= 0; i--) {
        if(jump[u][i] != jump[v][i]) {
            u = jump[u][i];
            v = jump[v][i];
        }
    }
    return jump[u][0];
}

void process(int node, int p) {
    for(auto& child : tree[node]) {
        if(child != p) {
            process(child, node);
            dp[node] += dp[child];
        }
    }
}

void solve() {
    int n, m;
    cin>>n>>m;
    tree = vector<vector<int>>(n+1);
    jump = vector<vector<int>>(n+1, vector<int>(21, -1));
    depth = vector<int>(n+1);
    dp = vector<int>(n+1);
    for(int i = 1; i < n; i++) {
        int u, v;
        cin>>u>>v;
        tree[u].push_back(v);
        tree[v].push_back(u);
    }
    dfs(1, 0);
    for(int d = 1; d < 21; d++) {
        for(int i = 1; i <= n; i++) {
            if(jump[i][d-1] != -1) {
                jump[i][d] = jump[jump[i][d-1]][d-1];
            }
        }
    }
    while(m--) {
        int a, b;
        cin>>a>>b;
        int lc = lca(a, b);
        dp[a]++;
        dp[b]++;
        dp[lc]--;
        dp[jump[lc][0]]--;
    }
    process(1, 0);
    for(int i = 1; i <= n; i++) {
        cout<<dp[i]<<" ";
    }
}