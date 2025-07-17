#include<bits/stdc++.h>
using namespace std;
#define int long long
#define pii pair<int,int>
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
int mod = 1e9 + 7;

void solve() {
    int n, m;
    cin>>n>>m;
    vector<vector<pair<int,int>>> graph(n+1);
    for(int i=0;i<m;i++) {
        int u, v, w;
        cin>>u>>v>>w;
        graph[u].push_back({v, w});
        // graph[v].push_back({u, w});
    }
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    pq.push({0, 1});
    vector<int> dist(n+1, inf);
    dist[1] = 0;
    vector<int> cnt(n+1);
    cnt[1] = 1;
    vector<int> min_len(n+1, inf);
    min_len[1] = 0;
    vector<int> max_len(n+1, -1);
    max_len[1] = 0;
    vector<bool> vis(n+1, false);
    // vis[1] = true
    while(!pq.empty()) {
        int node = pq.top().second;
        pq.pop();
        if(vis[node]) continue;
        vis[node] = true;
        for(auto& [child, w] : graph[node]) {
            if(vis[child]) continue;
            if(dist[child] > dist[node] + w) {
                dist[child] = w + dist[node];
                cnt[child] = cnt[node];
                min_len[child] = min_len[node] + 1;
                max_len[child] = max_len[node] + 1;
                pq.push({dist[child], child});
            }
            else if(dist[child] == dist[node] + w) {
                cnt[child] = (cnt[child] + cnt[node]) % mod;
                min_len[child] = min(min_len[child], min_len[node] + 1);
                max_len[child] = max(max_len[child], max_len[node] + 1);
                pq.push({dist[child], child});
            }
        }
    }
    cout<<dist[n]<<" "<<cnt[n]<<" "<<min_len[n]<<" "<<max_len[n];
}