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

bool check(int node, vector<vector<int>> &graph, vector<bool> &vis, int parent) {
    vis[node] = true;
    
    for(int i : graph[node]) {
        if(!vis[i]) {
            if(check(i, graph, vis, node)) return true;
        }
        else if(i != parent) return true;
    }
    return false;
}

void solve() {
    int n, m;
    cin>>n>>m;
    vector<vector<int>> graph(n);
    for(int i=0;i<m;i++) {
        int u,v;
        cin>>u>>v;
        u--;
        v--;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    
    vector<bool> vis(n, false);
    if(!check(0, graph, vis, -1)) {
        cout<<"No"<<endl;
        return;
    }
    for(int i=0;i<n;i++) {
        if(!vis[i]) {
            cout<<"No"<<endl;
            return;
        }
    }
    cout<<"Yes"<<endl;
}