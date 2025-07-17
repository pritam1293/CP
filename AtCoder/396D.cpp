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
    // cin>>t;
    while(t--)  solve();
    cerr << "time: " << (float)clock() / CLOCKS_PER_SEC << endl; return 0;
}

void dfs(int n, int u, int curr, int &ans, vector<bool> &vis, vector<vector<pair<int,int>>> &graph) {
    vis[u] = true;
    if(u == n) ans = min(curr, ans);
    for(auto pair : graph[u]) {
        int v = pair.first;
        int w = pair.second;
        if(!vis[v]) dfs(n,v,curr^w,ans,vis,graph);
    }
    vis[u] = false;
}

void solve() {
    int n,m;
    cin>>n>>m;
    vector<vector<pair<int,int>>> graph(n+1);
    for(int i=0;i<m;i++) {
        int u,v,w;
        cin>>u>>v>>w;
        graph[u].push_back({v,w});
        graph[v].push_back({u,w});
    }
    vector<bool> vis(n+1 , false);
    int ans = LLONG_MAX;
    dfs(n,1,0,ans,vis,graph);
    cout<<ans<<endl;
}