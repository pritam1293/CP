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

int inf = 1e17;//int defines long long

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
    for(int i=1;i<=n;i++) {
        for(auto& edge : edges) {
            int u = edge[0];
            int v = edge[1];
            int w = edge[2];
            if(dist[u] != inf && dist[v] > dist[u] + w) {
                if(i == n) {
                    cout<<"-1"<<endl;
                }
                dist[v] = dist[u] + w;
            }
        }
    }
    cout<< (dist[n] == inf ? -1 : dist[n]) <<endl;
}