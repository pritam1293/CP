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

void dfs(int node, vector<bool> &vis, vector<vector<int>> &graph) {
    vis[node] = true;
    for(auto& child : graph[node]) {
        if(!vis[child]) {
            dfs(child, vis, graph);
        }
    }
}

void solve() {
    int n, m;
    cin>>n>>m;
    vector<vector<int>> graph(n+1);
    for(int i=0;i<m;i++) {
        int u, v;
        cin>>u>>v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    vector<bool> vis(n+1, false);
    int cnt = 0;
    vector<int> nodes;
    for(int i=1;i<=n;i++) {
        if(!vis[i]) {
            dfs(i, vis, graph);
            cnt++;
            nodes.push_back(i);
        }
    }
    int roads = nodes.size()-1;
    cout<< roads <<endl;
    if(roads) {
        for(int i=0;i<roads;i++) {
            cout<<nodes[i]<<" "<<nodes[i+1]<<endl;
        }
    }
}