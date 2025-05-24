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

bool dfs(int node, vector<int> &vis, stack<int> &st, vector<vector<int>> &graph) {
    vis[node] = 1;
    for(auto& child : graph[node]) {
        if(!vis[child]) {
            if(dfs(child, vis, st, graph)) return true;
        }
        else if(vis[child] == 1) return true;
    }
    st.push(node);
    vis[node] = 2;
    return false;
}

void solve() {
    int n,m;
    cin>>n>>m;
    vector<vector<int>> graph(n+1);
    for(int i=0;i<m;i++) {
        int u, v;
        cin>>u>>v;
        graph[u].push_back(v);
    }
    vector<int> vis(n+1);
    stack<int> st;
    bool flag = false;
    for(int i=1;i<=n;i++) {
        if(vis[i]) continue;
        if(dfs(i, vis, st, graph)) {
            flag = true;
            break;
        }
    }
    if(flag) {
        cout<<"IMPOSSIBLE"<<endl;
    }
    else {
        while(!st.empty()) {
            cout<<st.top()<<" ";
            st.pop();
        }
    }
}