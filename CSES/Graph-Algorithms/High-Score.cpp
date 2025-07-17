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

int inf = 1e17;

void dfs(int node, vector<vector<int>> &graph, vector<bool> &vis) {
    vis[node] = true;
    for(auto& child : graph[node]) {
        if(!vis[child]) dfs(child, graph, vis);
    }
}

void solve() {
    int n, m;
    cin>>n>>m;
    vector<vector<int>> edges(m);
    vector<vector<int>> a(n+1), b(n+1);
    for(int i=0;i<m;i++) {
        int u, v, w;
        cin>>u>>v>>w;
        a[u].push_back(v);
        b[v].push_back(u);
        edges[i] = {u, v, -w};
    } 
    vector<bool> forward(n+1, false), backward(n+1, false);
    dfs(1, a, forward);
    dfs(n, b, backward);
    vector<int> dist(n+1, inf);
    dist[1] = 0;
    bool flag = false;
    for(int i=1;i<=n;i++) {
        flag = false;
        for(auto& edge : edges) {
            int u = edge[0];
            int v = edge[1];
            int w = edge[2];

            if(forward[u] && backward[v] && dist[v] > dist[u] + w) {
                flag = true;
                dist[v] = dist[u] + w;
            }
        }
    }
    if(flag) {
        cout<<"-1"<<endl;
        return;
    }
    cout<<(dist[n] == inf ? -1 : -dist[n])<<endl;
}