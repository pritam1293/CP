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
    vector<int> vis(n+1, -1);
    for(int i=1;i<=n;i++) {
        if(vis[i] != -1) continue;
        queue<pair<int,int>> q;
        q.push({i, 0});
        vis[i] = 0;
        while(!q.empty()) {
            int node = q.front().first;
            int color = q.front().second;
            q.pop();

            for(auto& child : graph[node]) {
                if(vis[child] == -1) {
                    q.push({child, !color});
                    vis[child] = !color;
                }
                else if(vis[child] == color) {
                    cout<<"IMPOSSIBLE"<<endl;
                    return;
                }
            }
        }
    }
    for(int i=1;i<=n;i++) {
        cout<<vis[i] + 1<<" ";
    }
}