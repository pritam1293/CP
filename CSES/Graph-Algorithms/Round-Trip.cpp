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

vector<int> parent;
int cycle_start, cycle_end;

bool dfs(int node, int par, vector<bool> &vis, vector<vector<int>> &graph) {
    vis[node] = true;
    for(auto& child : graph[node]) {
        if(child == par) continue;
        if(vis[child]) {
            cycle_start = child;
            cycle_end = node;
            return true;
        }
        parent[child] = node;
        if(dfs(child, node, vis, graph)) return true;
    }
    return false;
}

void solve() {
    int n, m;
    cin>>n>>m;
    parent.resize(n+1);
    vector<vector<int>> graph(n+1);
    for(int i=0;i<m;i++) {
        int u,v;
        cin>>u>>v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    vector<bool> vis(n+1, false);
    for(int i=1;i<=n;i++) {
        if(vis[i]) continue;
        if(dfs(i, -1, vis, graph)) {
            vector<int> path;
            path.push_back(cycle_start);
            while(cycle_end != cycle_start) {
                path.push_back(cycle_end);
                cycle_end = parent[cycle_end];
            }
            path.push_back(cycle_start);
            cout<<path.size()<<endl;
            for(auto& node : path) {
                cout<<node<<" ";
            }
            return;
        }
    }
    cout<<"IMPOSSIBLE"<<endl;
}