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

void dfs(int node, vector<bool> &vis, stack<int> &st, vector<vector<int>> &graph) {
    vis[node] = true;
    for(auto& child : graph[node]) {
        if(!vis[child]) dfs(child, vis, st, graph);
    }
    st.push(node);
}

void dfs2(int node, vector<bool> &vis, stack<int> &temp, vector<vector<int>> &rgraph) {
    vis[node] = true;
    temp.push(node);
    for(auto& child : rgraph[node]) {
        if(!vis[child]) dfs2(child, vis, temp, rgraph);
    }
}

void solve() {
    int n, m;
    cin>>n>>m;
    vector<vector<int>> graph(n+1), rgraph(n+1);
    for(int i=0;i<m;i++) {
        int u,v;
        cin>>u>>v;
        graph[u].push_back(v);
        rgraph[v].push_back(u);
    }
    stack<int> st;
    vector<bool> vis(n+1, false);
    for(int i=1;i<=n;i++) {
        if(!vis[i]) dfs(i, vis, st, graph);
    }
    vis = vector<bool>(n+1, false);
    vector<int> ans(n+1);
    int scc = 0;
    while(!st.empty()) {
        int node = st.top();
        st.pop();
        if(vis[node]) continue;
        scc++;
        stack<int> temp;
        dfs2(node, vis, temp, rgraph);
        while(!temp.empty()) {
            ans[temp.top()] = scc;
            temp.pop();
        }
    }
    cout<<scc<<endl;
    for(int i=1;i<=n;i++) {
        cout<<ans[i]<<" ";
    }
}