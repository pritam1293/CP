#include<bits/stdc++.h>
using namespace std;
#define int long long
void solve();
int32_t main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
#ifndef ONLINE_JUDGE
    freopen("../../input.txt", "r", stdin);
    freopen("../../output.txt", "w", stdout);
#endif
    int t=1;
    // cin>>t;
    while(t--)  solve();
    cerr << "time: " << (float)clock() / CLOCKS_PER_SEC << endl; return 0;
}

int inf = 1e17;

void dijkstra(vector<vector<pair<int,int>>> &graph, vector<int> &dist, int node) {
    dist[node] = 0;
    set<pair<int,int>> st;
    st.insert({0, node});
    while(!st.empty()) {
        node = st.begin()->second;
        st.erase(st.begin());
 
        for(auto& [child, w] : graph[node]) {
            if(dist[child] > dist[node] + w) {
                if(st.contains({dist[child], child})) {
                    st.erase({dist[child], child});
                }

                dist[child] = dist[node] + w;
                st.insert({dist[child], child});
            }
        }
    }
}

void solve() {
    int n, m;
    cin>>n>>m;
    vector<vector<pair<int,int>>> a(n+1), b(n+1);
    for(int i=0;i<m;i++) {
        int u, v, w;
        cin>>u>>v>>w;
        a[u].push_back({v, w});
        b[v].push_back({u, w});
    }
    vector<int> forward(n+1, inf), backward(n+1, inf);
    dijkstra(a, forward, 1);
    dijkstra(b, backward, n);
    int ans = inf;
    for(int u=1;u<=n;u++) {
        for(auto& [v, w] : a[u]) {
            ans = min(ans, forward[u] + backward[v] + w/2);
        }
    }
    // for(auto& val : forward) {
    //     cout<<val<<" ";
    // }
    // cout<<endl;
    // for(auto& val : backward) {
    //     cout<<val<<" ";
    // }
    // cout<<endl;
    cout<<ans<<endl;
}