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

bool check(vector<vector<pair<int,int>>> &graph, int n, int x, int d, int &edge) {
    vector<bool> vis(n+1);
    vector<int> q = {1};
    vis[1] = true;
    for(int y=0;y<d;y++){
        vector<int> new_q;
        //do this for every node in q
        for(auto &[v,w] : graph[u]) {
            if(w > weight) continue;

            if(!vis[v]) {
                parent[v] = u;
                q.push(v);
                vis[v] = true;
            }
        }

        q = new_q;
    }
    return false;
}

void getPath(vector<vector<pair<int,int>>> &graph, int n, int weight) {
    vector<int> parent(n+1);
    vector<bool> vis(n+1);

    queue<int> q;
    q.push(1);//node and count
    vis[1] = true;
    while(!q.empty()) {
        int u = q.front();
        q.pop();
        for(auto &[v,w] : graph[u]) {
            if(w > weight) continue;

            if(!vis[v]) {
                parent[v] = u;
                q.push(v);
                vis[v] = true;
            }
        }
    }
    
    vector<int> path = {n};
    int node = n;
    while(node != 1) {
        node = parent[node];
        path.push_back(node);
    }
    reverse(path.begin(), path.end());
    for(auto& node : path) {
        cout<<node<<" ";
    }
}

void solve() {
    int n,m,d;
    cin>>n>>m>>d;
    int maxm = 0;
    vector<vector<pair<int,int>>> graph(n+1);
    for(int i=0;i<m;i++) {
        int u,v,w;
        cin>>u>>v>>w;
        graph[u].push_back({v, w});
        maxm = max(maxm, w);
    }

    int low = 0, high = maxm;
    int edge = -1;
    int weight = -1;
    while(low <= high) {
        int mid = low + (high - low) / 2;

        if(visit(graph, n, mid, d, edge)) {
            high = mid-1;
            weight = mid;
        }
        else {
            low = mid+1;
        }
    }
    cout<<edge<<endl;
    if(edge != -1) {
        getPath(graph, n, weight);
    }
}