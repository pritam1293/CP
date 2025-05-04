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

bool visit(vector<vector<pair<int,int>>> &graph, int n, int x, int d, int &edge) {
    queue<pair<int,int>> q;
    vector<bool> vis(n+1);
    q.push({1, 1});
    vis[1] = true;

    while(!q.empty()) {
        int u = q.front().first;
        int cnt = q.front().second;
        
        q.pop();

        if(cnt > d) continue;

        for(auto& pair : graph[u]) {
            int v = pair.first;
            int w = pair.second;

            if(w > x) continue;

            if(v == n) {
                edge = cnt;
                return true;
            }
            if(!vis[v]) {
                q.push({v, cnt+1});
                vis[v] = true;
            }
        }
    }
    return false;
}

void dfs(int node, int n, int d, int weight, vector<vector<pair<int,int>>> &graph, bool &found, vector<int> &path, vector<bool> &vis) {
    if(path.size() > d) return;
    path.push_back(node);
    vis[node] = true;
    if(node == n) {
        found = true;
        return;
    }

    for(auto& it : graph[node]) {
        if(it.second > weight) continue;
        if(!vis[it.first]) {
            dfs(it.first, n, d, weight, graph, found, path, vis);
        }
        if(found) return;
    }

    if(found) return;
    path.pop_back();
    vis[node] = false;
}

void solve() {
    int n,m,d;
    cin>>n>>m>>d;
    int maxm = 0;
    vector<vector<pair<int,int>>> graph(n+1);
    for(int i=0;i<m;i++) {
        int u,v,w;
        cin>>u>>v>>w;
        graph[u].push_back({v, w});
        maxm = max(maxm, w);
    }

    int low = 0, high = maxm;
    int edge = -1;
    int weight = -1;
    while(low <= high) {
        int mid = low + (high - low) / 2;

        if(visit(graph, n, mid, d, edge)) {
            high = mid-1;
            weight = mid;
        }
        else {
            low = mid+1;
        }
    }
    cout<<edge<<endl;
    if(edge == -1) return;
    
    queue<pair<int,int>> q;
    vector<int> path;
    bool found = false;
    vector<bool> vis(n+1);
    dfs(1, n, edge, weight, graph, found, path, vis);
    for(auto& node : path) {
        cout<<node<<" ";
    }
}