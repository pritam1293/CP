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

#define ll long long
vector<vector<pair<int,int>>> tree;
vector<vector<ll>>parent, weight;
vector<ll> depth, dw;

void dfs(int node, int par, ll wt) {
    depth[node] = 1 + depth[par];
    dw[node] = wt + dw[par];
    parent[node][0] = par;
    weight[node][0] = wt;
    for(auto& [child, w] : tree[node]) {
        if(child != par) dfs(child, node, w);
    }
}

int lca(int u, int v) {
    if(depth[u] > depth[v]) swap(u, v);
    int d = depth[v] - depth[u];
    for(int i=0;i<20;i++) {
        if(1 & (d >> i)) v = parent[v][i];
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

int jump(int node, int d) {
    for(int i=0;i<20;i++) {
        if(1 & (d >> i)) node = parent[node][i];
    }
    return node;
}
vector<int> findMedian(int n, vector<vector<int>>& edges, vector<vector<int>>& queries) {
    tree = vector<vector<pair<int,int>>>(n);
    parent = vector<vector<ll>>(n, vector<ll>(20, -1));
    weight = vector<vector<ll>>(n, vector<ll>(20));
    depth = vector<ll>(n);
    dw = vector<ll>(n);
    for(auto& edge : edges) {
        int u = edge[0];
        int v = edge[1];
        int w = edge[2];
        tree[u].push_back({v, w});
        tree[v].push_back({u, w});
    }
    dfs(0, 0 ,0);
    for(int d=1;d<20;d++) {
        for(int i=0;i<n;i++) {
            if(parent[i][d-1] != -1) {
                parent[i][d] = parent[parent[i][d-1]][d-1];
                weight[i][d] = weight[i][d-1] + weight[parent[i][d-1]][d-1];
            }
        }
    }
    vector<int> ans;
    for(auto& q : queries) {
        int a = q[0];
        int b = q[1];
        int lc = lca(a, b);
        ll tot = (dw[a] + dw[b] - 2*dw[lc]);
        ll tar = (tot + 1)/2;

        if(dw[a] - dw[lc] >= tar) {
            int d = depth[a] - depth[lc];
            int low = 1, high = d;
            int node = lc;
            while(low <= high) {
                int mid = (low + high) / 2;
                int mid_node = jump(a, mid);
                if(dw[a] - dw[mid_node] >= tar) {
                    node = mid_node;
                    high = mid-1;
                }
                else {
                    low = mid+1;
                }
            }
            ans.push_back(node);
        }
        else {
            int d = depth[b] - depth[lc];
            int low = 0, high = d-1, node = b;
            ll c = dw[a] - dw[lc];
            while(low <= high) {
                int mid = (low + high) / 2;
                int mid_node = jump(b, mid);
                if(c + dw[mid_node] - dw[lc] >= tar) {
                    node = mid_node;
                    low = mid+1;
                }
                else {
                    high = mid-1;
                }
            }
            ans.push_back(node);
        }
    }
    return ans;
}

void solve() {
    vector<vector<int>> a = {{0,1,2},{0,2,5},{1,3,1},{2,4,3}};
    vector<vector<int>> q = {{3, 4}, {1, 2}};
    for(auto it : findMedian(5, a, q)) {
        cout<<it<<" ";
    }
}