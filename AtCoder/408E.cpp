#include<bits/stdc++.h>
using namespace std;
#define int long long
void solve();
int32_t main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
#ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
#endif
    int t=1;
    while(t--)  solve();
    cerr << "time: " << (float)clock() / CLOCKS_PER_SEC << endl; return 0;
}

void solve() {
    int n, m;
    cin>>n>>m;
    vector<vector<pair<int,int>>> graph(n+1);
    for(int i=0;i<m;i++) {
        int u, v, w;
        cin>>u>>v>>w;
        graph[u].push_back({v, w});
        graph[v].push_back({u, w});
    }
    queue<pair<int,int>> q;
    q.push({1, 0});
    vector<int> vis(n, false);
    vis[1] = true;
    int ans = LLONG_MAX;
    while(!q.empty()) {
        int node = q.front().first;
        int wt = q.front().second;
        if(node == n) ans = min(ans, wt);
        for(auto& [child, w] : graph[node]) {
            if(!vis[child]) {
                
            }
        }
    }
}