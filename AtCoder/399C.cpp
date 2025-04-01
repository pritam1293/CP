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

int countCompleteComponents(int n, vector<vector<int>>& edges) {
    // Create adjacency list representation of the graph
    vector<vector<int>> graph(n);
    for (const auto& edge : edges) {
        int u = edge[0], v = edge[1];
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    vector<bool> visited(n, false);
    int completeComponents = 0;

    // Process each unvisited vertex
    for (int vertex = 0; vertex < n; vertex++) {
        if (!visited[vertex]) {
            // BFS to find all vertices in the current component
            vector<int> component;
            queue<int> q;
            q.push(vertex);
            visited[vertex] = true;

            while (!q.empty()) {
                int current = q.front();
                q.pop();
                component.push_back(current);

                // Process neighbors
                for (int neighbor : graph[current]) {
                    if (!visited[neighbor]) {
                        q.push(neighbor);
                        visited[neighbor] = true;
                    }
                }
            }

            // Check if component is complete (all vertices have the right
            // number of edges)
            bool isComplete = true;
            for (int node : component) {
                if (graph[node].size() != component.size() - 1) {
                    isComplete = false;
                    break;
                }
            }

            if (isComplete) {
                completeComponents++;
            }
        }
    }

    return completeComponents;
}

void solve() {
    int v,e;
    cin>>v>>e;
    if(e == 0) {
        cout<<"0";
        return;
    }
    set<int> st;
    vector<vector<int>> edges(e);
    for(int i=0;i<e;i++) {
        int u,v;
        cin>>u>>v;
        st.insert(u);
        st.insert(v);
        edges[i] = {u-1,v-1};
    }
    int com = countCompleteComponents(v, edges);
    if(com) com--;
    cout<<e + 1- (int)st.size() + com <<endl;
}