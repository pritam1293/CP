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
    while(t--)  solve();
    cerr << "time: " << (float)clock() / CLOCKS_PER_SEC << endl; return 0;
}

void solve() {
    int n, m;
    cin>>n>>m;
    vector<vector<pair<int,int>>> graph(n+1);
    for(int i=0;i<m;i++) {
        int u, v, w;
        cin>>u>>v>>w;
        graph[u].push_back({v, w});
        // graph[v].push_back({u, w});
    }
    vector<int> dist(n+1, LLONG_MAX);
    set<pair<int, int>> st;
    st.insert({0, 1});
    dist[1] = 0;
    while(!st.empty()) {
        int node = st.begin()->second;
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
    for(int i=1;i<=n;i++) {
        cout<<dist[i]<<" ";
    }
}