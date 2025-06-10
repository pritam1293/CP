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
    vector<int> indeg(n+1);
    for(int i=0;i<m;i++) {
        int u, v;
        cin>>u>>v;
        graph[u].push_back(v);
        indeg[v]++;
    }
    if(graph[1].size() - indeg[1] != 1 || indeg[n] - graph[n].size() != 1) {
        cout<<"IMPOSSIBLE"<<endl;
        return;
    }
    for(int i=2;i<n;i++) {
        if(indeg[i] != graph[i].size()) {
            cout<<"IMPOSSIBLE"<<endl;
            return;
        }
    }
    stack<int> st;
    st.push(1);
    vector<int> path;
    while(!st.empty()) {
        int node = st.top();
        if(indeg[node] == 0 && graph[node].size() == 0) {
            path.push_back(node);
            st.pop();
        }
        else {
            st.push(graph[node].back());
            indeg[graph[node].back()]--;
            graph[node].pop_back();
        }
    }
    // cout<<"ex1"<<endl;
    if(path.size() != m+1) {
        cout<<"IMPOSSIBLE"<<endl;
    }
    else {
        reverse(path.begin(), path.end());
        for(auto& node : path) {
            cout<<node<<" ";
        }
    }
}