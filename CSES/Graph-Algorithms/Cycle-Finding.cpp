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

void solve() {
    int n, m;
    cin>>n>>m;
    vector<vector<int>> edges(m);
    for(int i=0;i<m;i++) {
        int u, v, w;
        cin>>u>>v>>w;
        edges[i] = {u, v, w};
    }
    vector<int> dist(n+1, inf);
    dist[1] = 0;
    int node = -1;
    vector<int> parent(n+1);
    for(int i=1;i<=n;i++) {
        node = -1;
        for(auto& edge : edges) {
            int u = edge[0];
            int v = edge[1];
            int w = edge[2];
            if(dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                parent[v] = u;
                node = v;
            }
        }
    }
    if(node == -1) {
        cout<<"NO"<<endl;
    }
    else {
        cout<<"YES"<<endl;
        for(int i=1;i<=n;i++) {
            node = parent[node];
        }
        vector<int> cycle;
        for(int v = node;; v = parent[v]) {
            cycle.push_back(v);
            if(v == node && cycle.size() > 1) {
                break;
            } 
        }
        reverse(cycle.begin(), cycle.end());
        for(auto& val : cycle) {
            cout<<val<<" ";
        }
    }
}