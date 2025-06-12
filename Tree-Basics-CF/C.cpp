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
    if (depth[v] < depth[u]) swap(u, v); 
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
    int n;
    cin>>n;
    tree = vector<vector<int>>(n+1);
    for(int i=1;i<n;i++) {
        int u, v;
        cin>>u>>v;
        tree[u].push_back(v);
        tree[v].push_back(u);
    }
    parent = vector<vector<int>>(n+1, vector<int>(20, -1));
    depth = vector<int>(n+1);
    dfs(1, 0);
    for(int d = 1; d < 20; d++) {
        for(int i = 1; i <= n; i++) {
            if(parent[i][d-1] != -1) {
                parent[i][d] = parent[parent[i][d-1]][d-1];
            }
        }
    }
    // int node = lca(1, 5);
    // cout<<depth[node] - depth[1]<<endl;
    // cout<<depth[node] - depth[5]<<endl;
    int q;
    cin>>q;
    while(q--) {
        int a, b, c;
        cin>>a>>b>>c;
        int lc = lca(a, b);
        int dist = depth[a] + depth[b] - 2 * depth[lc];
        int node = a;
        if(c >= dist) {
            node = b;
        }
        else {
            int d = depth[a] - depth[lc];
            if(d >= c) {
                for(int i = 0; i < 20; i++) {
                    if(1 & (c >> i)) node = parent[node][i];
                }
            }
            else {
                node = b;
                c = dist - c;
                for(int i = 0; i < 20; i++) {
                    if(1 & (c >> i)) node = parent[node][i];
                }
            }
        }
        cout<<node<<endl;
    }
}