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
    int n, m, k;
    cin>>n>>m>>k;
    vector<vector<pair<int,int>>> graph(n+1);
    for(int i=0;i<m;i++) {
        int u, v, w;
        cin>>u>>v>>w;
        graph[u].push_back({v, w});
        // graph[v].push_back({u, w});
    }
    vector<vector<int>> dist(n+1, vector<int>(k, inf));
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    pq.push({0,1});
    dist[1][0] = 0;

    while(!pq.empty()) {
        int d = pq.top().first;
        int node = pq.top().second;
        pq.pop();

        if(dist[node][k-1] < d) continue;

        for(auto& [child, w] : graph[node]) {
            if(d + w < dist[child][k-1]) {
                dist[child][k-1] = d + w;
                sort(dist[child].begin(), dist[child].end());
                pq.push({d + w, child});
            }
        }
    }
    for(int i=0;i<k;i++) {
        cout<<dist[n][i]<<" ";
    }
}