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

vector<int> dist;

void dfs(int node, int parent, vector<vector<int>> &tree) {
    for(auto& child : tree[node]) {
        if(child != parent) {
            dist[child] = 1 + dist[node];
            dfs(child, node, tree);
        }
    }
}

void solve() {
    int n;
    cin>>n;
    vector<vector<int>> tree(n+1);
    for(int i=1;i<n;i++) {
        int u, v;
        cin>>u>>v;
        tree[u].push_back(v);
        tree[v].push_back(u);
    }
    dist = vector<int>(n+1);
    dfs(1, -1, tree);
    int len = 0, node = 1;
    for(int i=1;i<=n;i++) {
        if(dist[i] > len) {
            len = dist[i];
            node = i;
        }
    }
    dist = vector<int>(n+1);
    dfs(node, -1, tree);
    for(int i=1;i<=n;i++) {
        len = max(len, dist[i]);
    }
    cout<<len<<endl;
}