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

vector<bool> vis;
vector<int> dp, parent;

void check(int node, vector<vector<int>> &graph) {
    vis[node] = true;
    for(auto& child : graph[node]) {
        if(!vis[child]) check(child, graph);
    }
}

int dfs(int node, int n, vector<vector<int>> &graph) {
    if(node == n) return dp[n] = 1;
    if(dp[node] != -1) return dp[node];

    int len = 0;
    for(auto& child : graph[node]) {
        int temp = dfs(child, n, graph);
        int temp_len = (temp == 0) ? 0 : 1 + temp;
        // cout<<temp_len<<endl;
        if(temp_len > len) {
            parent[node] = child;
            len = temp_len;
        }
    }
    return dp[node] = len;
}

void solve() {
    int n, m;
    cin>>n>>m;
    vector<vector<int>> graph(n+1);
    for(int i=0;i<m;i++) {
        int u,v;
        cin>>u>>v;
        graph[u].push_back(v);
        // graph[v].push_back(u);
    }
    vis = vector<bool>(n+1, false);
    check(1, graph);
    if(!vis[n]) {
        cout<<"IMPOSSIBLE"<<endl;
    }
    else {
        dp = vector<int>(n+1, -1);
        parent = vector<int>(n+1);
        dfs(1, n, graph);
        // for(int i=1;i<=n;i++) {
        //     cout<<i<<" "<<parent[i]<<endl;
        // }
        int node = 1;
        vector<int> path = {node};
        while(node != n) {
            node = parent[node];
            path.push_back(node);
        }
        // reverse(path.begin(), path.end());
        cout<<path.size()<<endl;
        for(auto& it : path) {
            cout<<it<<" ";
        }
    }
}