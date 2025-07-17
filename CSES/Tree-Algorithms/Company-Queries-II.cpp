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

vector<vector<int>> tree, parent;
vector<int> depth;

void dfs(int node, int par) {
    depth[node] = 1 + depth[par];
    parent[node][0] = par;
    for(auto& child : tree[node]) {
        if(child != par) dfs(child, node);
    }
}

int lca(int u, int v) {
    if(depth[u] > depth[v]) swap(u, v);
    int diff = depth[v] - depth[u];
    for(int i=0;i<20;i++) {
        if(1 & (diff >> i)) v = parent[v][i];
    }
    if(u == v) return u;
    for(int i=19;i>=0;i--) {
        if(parent[u][i] != parent[v][i]) {
            u = parent[u][i];
            v = parent[v][i];
        }
    }
    return parent[u][0];
}

void solve() {
    int n, q;
    cin>>n>>q;
    tree = vector<vector<int>>(n+1);
    parent = vector<vector<int>>(n+1, vector<int>(20, -1));;
    depth = vector<int>(n+1);
    for(int i=2;i<=n;i++) {
        int v;
        cin>>v;
        tree[i].push_back(v);
        tree[v].push_back(i);
    }
    dfs(1, 0);
    for(int d=1;d<20;d++) {
        for(int i=1;i<=n;i++) {
            if(parent[i][d-1] != -1) {
                parent[i][d] = parent[parent[i][d-1]][d-1];
            }
        }
    }
    while(q--) {
        int u, v;
        cin>>u>>v;
        cout<<lca(u, v)<<endl;
    }
}