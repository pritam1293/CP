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

void dfs(int node, int parent, int len, vector<vector<int>> &tree) {
    dist[node] = len;
    for(auto& child : tree[node]) {
        if(child != parent) dfs(child, node, len+1, tree);
    }
}

void solve() {
    int n, q;
    cin>>n>>q;
    vector<vector<int>> tree(n+1);
    vector<vector<int>> parent(n+1, vector<int>(30));
    parent[1][0] = 1;
    for(int i=2;i<=n;i++) {
        int v;
        cin>>v;
        tree[i].push_back(v);
        tree[v].push_back(i);
        parent[i][0] = v;
    }
    dist = vector<int>(n+1);
    dfs(1, -1, 0, tree);
    for(int d=1;d<30;d++) {
        for(int i=1;i<=n;i++) {
            parent[i][d] = parent[parent[i][d-1]][d-1];
        }
    }
    while(q--) {
        int node, d;
        cin>>node>>d;
        if(d > dist[node]) {
            cout<<"-1"<<"\n";
            continue;
        }
        for(int i=0;i<30;i++) {
            if(1 & (d >> i)) node = parent[node][i];
        }
        cout<<node<<"\n";
    }

}