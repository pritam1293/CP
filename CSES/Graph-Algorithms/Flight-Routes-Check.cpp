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

vector<bool> vis;

void dfs(int node, vector<vector<int>> &graph) {
    vis[node] = true;
    for(auto& child : graph[node]) {
        if(!vis[child]) dfs(child, graph);
    }
}

void solve() {
    int n, m;
    cin>>n>>m;
    vector<vector<int>> forward(n+1), backward(n+1);
    for(int i=0;i<m;i++) {
        int u,v;
        cin>>u>>v;
        forward[u].push_back(v);
        backward[v].push_back(u);
    }
    vis = vector<bool> (n+1, false);
    dfs(1, forward);
    for(int i=1;i<=n;i++) {
        if(!vis[i]) {
            cout<<"NO"<<endl;
            cout<<"1 "<<i<<endl;
            return;
        }
        vis[i] = false;
    }

    dfs(1, backward);
    for(int i=1;i<=n;i++) {
        if(!vis[i]) {
            cout<<"NO"<<endl;
            cout<<i<<" "<<1<<endl;
            return;
        }
    }
    cout<<"YES"<<endl;
}