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

int cycle_start, cycle_end;

bool dfs(int node, vector<int> &vis, vector<int> &parent, vector<vector<int>> &graph) {
    vis[node] = 1;
    for(auto& child : graph[node]) {
        if(!vis[child]) {
            parent[child] = node;
            if(dfs(child, vis, parent, graph)) return true;
        }
        else if(vis[child] == 1) {
            cycle_start = child;
            cycle_end = node;
            return true;
        }
    }
    vis[node] = 2;
    return false;
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
    vector<int> vis(n+1);
    vector<int> parent(n+1);
    bool flag = false;
    for(int i=1;i<=n;i++) {
        if(vis[i]) continue;
        if(dfs(i, vis, parent, graph)) {
            flag = true;
            break;
        }
    }
    if(!flag) {
        cout<<"IMPOSSIBLE"<<endl;
        return;
    }
    vector<int> cycle;
    cycle.push_back(cycle_start);
    int node = cycle_end;
    while(node != cycle_start) {
        cycle.push_back(node);
        node = parent[node];
    }
    cycle.push_back(cycle_start);
    int len = cycle.size();
    cout<<len<<endl;
    for(int i = len-1; i >=0; i--) {
        cout<<cycle[i]<<" ";
    }
}