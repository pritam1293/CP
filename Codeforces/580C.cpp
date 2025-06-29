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
    while(t--)  solve();
    cerr << "time: " << (float)clock() / CLOCKS_PER_SEC << endl; return 0;
}

vector<vector<int>> tree;
vector<int> cat, leaf, dp;

void dfs(int node, int par, int cnt) {
    if(tree[node].size() == 1 && node != 1) leaf.push_back(node);
    dp[node] = max(dp[par], cnt);
    for(auto& child : tree[node]) {
        if(child != par) {
            if(cat[child] == 1) dfs(child, node, cnt+1);
            else dfs(child, node, 0);
        }
    } 
}

void solve() {
    int n, m;
    cin>>n>>m;
    tree = vector<vector<int>>(n+1);
    cat = vector<int>(n+1);
    dp = vector<int>(n+1);
    for(int i=1;i<=n;i++) cin>>cat[i];
    for(int i=1;i<n;i++) {
        int u, v;
        cin>>u>>v;
        tree[u].push_back(v);
        tree[v].push_back(u);
    }
    int cnt = cat[1] == 1;
    dfs(1, 0, cnt);
    cnt = 0;
    for(auto& node : leaf) {
        // cout<<node<<" ";
        if(dp[node] <= m) cnt++;
    }
    // cout<<endl;
    cout<<cnt<<endl;
}