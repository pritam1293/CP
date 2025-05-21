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

void solve() {
    int n, m;
    cin>>n>>m;
    vector<vector<int>> graph(n+1);
    for(int i=0;i<m;i++) {
        int u,v;
        cin>>u>>v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    vector<bool> vis(n+1, false);
    vector<int> parent(n+1);
    queue<int> q;
    q.push(1);
    vis[1] = true;

    while(!q.empty()) {
        int node = q.front();
        q.pop();
        if(node == n) break;
        for(auto& child : graph[node]) {
            if(!vis[child]) {
                parent[child] = node;
                q.push(child);
                vis[child] = true;
            }
        }
    }
    if(!vis[n]) {
        cout<<"IMPOSSIBLE"<<endl;
        return;
    }
    vector<int> path = {n};
    int node = n;
    while(node != 1) {
        node = parent[node];
        path.push_back(node);
    }
    int len = path.size();
    cout<<len<<endl;
    for(int i = len-1; i >= 0; i--) {
        cout<<path[i]<<" ";
    }
}