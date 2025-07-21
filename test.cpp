#include<bits/stdc++.h>
using namespace std;
#define int long long
void solve();
int32_t main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int t=1;
    while(t--)  solve();
    cerr << "time: " << (float)clock() / CLOCKS_PER_SEC << endl; return 0;
}

int inf = 1e9;
vector<set<int>> graph;

int dijkstra(int n, int src, int tar) {
    vector<int> dist(n+1, inf);
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    dist[src] = 1;
    pq.push({0, src});
    while(!pq.empty()) {
        int node = pq.top().second;
        pq.pop();
        
        for(auto& child : graph[node]) {
            if(dist[node] + 1 < dist[child]) {
                dist[child] = 1 + dist[node];
                pq.push({dist[child], child});
            }
        }
    }
    return dist[tar];
}

int Solutionsolve(int n, vector<vector<int>> &edges, int src, int tar, vector<vector<int>> &extra) {
    graph = vector<set<int>>(n+1);
    for(auto& e : edges) {
        graph[e[0]].insert(e[1]);
        graph[e[1]].insert(e[0]);
    }
    int ans = inf;
    ans = min(ans, dijkstra(n, src, tar));
    for(auto& e : extra) {
        graph[e[0]].insert(e[1]);
        graph[e[1]].insert(e[0]);
        ans = min(ans, dijkstra(n, src, tar));
        graph[e[0]].erase(e[1]);
        graph[e[1]].erase(e[0]);
    }
    if(ans == inf) ans = -1;
    return ans;
}

void solve() {
    int n = 3;
    vector<vector<int>> edges = {{1,2,1}, {2,3,2}};
    int src = 1;
    int tar = 3;
    vector<vector<int>> extra = {{1,3,2}};
    cout<<Solutionsolve(n, edges, src, tar, extra)<<endl;
    n = 4;
    edges = {{1,2,1}, {2,3,2}, {3, 1, 4}};
    src = 1;
    tar = 4;
    extra = {{1, 3, 2}};
    cout<<Solutionsolve(n, edges, src, tar, extra)<<endl;
}