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

int inf = 1e17;

void solve() {
    int n, m, q;
    cin>>n>>m>>q;
    vector<vector<pair<int,int>>> graph(n+1);
    vector<vector<int>> dist(n+1, vector<int>(n+1, inf));
    for(int i=1;i<=n;i++) {
        dist[i][i] = 0;
    }
    for(int i=0;i<m;i++) {
        int u, v, w;
        cin>>u>>v>>w;
        graph[u].push_back({v, w});
        graph[v].push_back({u, w});
        dist[u][v] = min(dist[u][v], w);
        dist[v][u] = min(dist[v][u], w);
    }
    for(int via = 1; via <= n; via++) {
        for(int i=1;i<=n;i++) {
            for(int j=1;j<=n;j++) {
                dist[i][j] = min(dist[i][j], dist[i][via] + dist[via][j]);
            }
        }
    }
    for(int i=0;i<q;i++) {
        int u, v;
        cin>>u>>v;
        cout<< (dist[u][v] == inf ? -1 : dist[u][v])<<endl;
    }
}