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

vector<vector<pair<int,int>>> graph;
vector<int> degree, path;
vector<bool> vis;

void dfs(int node) {
    while(!graph[node].empty()) {
        auto [child, idx] = graph[node].back();
        graph[node].pop_back();
        if(!vis[idx]) {
            vis[idx] = true;
            dfs(child);
        }
    }
    path.push_back(node);
}

void solve() {
    int n, m;
    cin>>n>>m;
    graph = vector<vector<pair<int,int>>>(n+1);
    degree = vector<int>(n+1);
    vis = vector<bool>(m, false);
    for(int i=0;i<m;i++) {
        int u, v;
        cin>>u>>v;
        graph[u].push_back({v, i});
        graph[v].push_back({u, i});
        degree[u]++;
        degree[v]++;
    }

    for(int i=1;i<=n;i++) {
        if(degree[i] % 2) {
            cout<<"IMPOSSIBLE"<<endl;
            return;
        }
    }
    dfs(1);
    // cout<<path.size()<<endl;
    // for(auto& node : path) {
    //         cout<<node<<" ";
    //     }
    if(path.size() != m+1) {
        cout<<"IMPOSSIBLE"<<endl;
    }
    else {
        for(auto& node : path) {
            cout<<node<<" ";
        }
    }
}