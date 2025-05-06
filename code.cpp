#include<bits/stdc++.h>
using namespace std;
void solve();
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int t=1;
    // cin>>t;
    while(t--)  solve();
    cerr << "time: " << (float)clock() / CLOCKS_PER_SEC << endl; return 0;
}

int cycle_start = -1;
int cycle_end = -1;

bool check(int node, vector<vector<int>> &graph, vector<int> &vis, vector<int> &parent) {
    vis[node] = 1;
    for(auto& child : graph[node]) {
        if(!vis[child]) {
            parent[child] = node;
            if(check(child, graph, vis, parent)) return true;
        }
        else if(vis[child] == 1) {
            cycle_start = child;
            cycle_end = node;
            return true;
        }
    }
    vis[node] = 2;
    return false;
}

void solve() {
    int n, m;
    cin>>n>>m;
    vector<vector<int>> graph(n+1);
    for(int i=0;i<m;i++) {
        int u, v;
        cin>>u>>v;
        graph[u].push_back(v);
    }
    vector<int>vis(n+1);
    vector<int> parent(n+1);
    for(int i=1;i<=n;i++) {
        if(!vis[i]) {
            if(check(i, graph, vis, parent)) {
                cout<<"yes"<<endl;

                //printing the cycle
                vector<int> cycle;
                cycle.push_back(cycle_start);
                int node = cycle_end;
                while(node != cycle_start) {
                    cycle.push_back(node);
                    node = parent[node];
                }
                cycle.push_back(cycle_start);
                reverse(cycle.begin(), cycle.end());
                for(auto& node : cycle) {
                    cout<<node<<" ";
                }
                cout<<endl;
                return;
            }
        }
    }
    cout<<"no"<<endl;

}
