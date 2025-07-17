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

vector<vector<int>> parent, minw;
vector<vector<pair<int,int>>> graph;
vector<int> depth;

void dfs(int node, int par, int wt = 0) {
    depth[node] = 1 + depth[par];
    parent[node][0] = par;
    minw[node][0] = wt;
    for(auto& [child, w] : graph[node]) {
        if(child != par) {
            dfs(child, node, w);
        }
    }
}

int lca(int u, int v) {
    if(depth[u] > depth[v]) swap(u, v);
    int diff = depth[v] - depth[u];

    for (int i = 0; i < 20; i++) {
        if ((diff>>i)&1) v = parent[v][i]; 
    }
    if (u == v) return u; 

    for (int i = 19; i >= 0; i--) {
        if (parent[u][i] != parent[v][i]) { 
            u = parent[u][i]; 
            v = parent[v][i]; 
        } 
    }
    return parent[u][0]; 
}

void solve() {
    int n, m;
    cin>>n>>m;
    graph = vector<vector<pair<int,int>>>(n+1);
    for(int i=0;i<m;i++) {
        int u, v, w;
        cin>>u>>v>>w;
        graph[u].push_back({v, w});
        graph[v].push_back({u, w});
    }
    parent = vector<vector<int>>(n+1, vector<int>(20, -1));
    minw = vector<vector<int>>(n+1, vector<int>(20, 1e9));
    depth = vector<int>(n+1);
    dfs(1, 0);

    for(int d = 1; d < 20; d++) {
        for(int i = 1; i <= n; i++) {
            if(parent[i][d-1] != -1){
                parent[i][d] = parent[parent[i][d-1]][d-1];
                minw[i][d] = min(minw[parent[i][d-1]][d-1], minw[i][d-1]);
            }
              
        }
    }

    // for(int d=0;d<20;d++) {
    //     // cout<<d<<"->"<<endl;
    //     for(int i=1;i<=n;i++) {
    //         // cout<<i<<": "<<parent[i][d]<<" "<<minw[i][d]<<endl;
    //     }
    //     // cout<<endl;
    // }
    int q;
    cin>>q;
    while(q--) {
        int a, b;
        cin>>a>>b;
        int ans = INT_MAX;
        int lc = lca(a, b);
        int d = depth[a] - depth[lc];
        if(d > 0) {
            for(int i = 0; i < 20; i++) {
                if(1 & (d >> i)) {
                    ans = min(ans, minw[a][i]);
                    a = parent[a][i];
                }
            }
        }
        d = depth[b] - depth[lc];
        if(d > 0) {
            for(int i = 0; i < 20; i++) {
                if(1 & (d >> i)) {
                    ans = min(ans, minw[b][i]);

                    b = parent[b][i];
                }
            }
        }
        cout<<ans<<endl;
    }
}