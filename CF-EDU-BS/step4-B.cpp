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

bool check(vector<vector<pair<int,int>>> &graph, int n, double mid, vector<int> &parent) {
    vector<double> dp(n+1, 1e9);
    dp[1] = 0;
    for(int u = 1; u <= n; u++) {
        for(auto& pair : graph[u]) {
            int v = pair.first;
            int w = pair.second;
            if(dp[v] > dp[u] + w - mid) {
                dp[v] = dp[u] + w - mid;
                parent[v] = u;
            }
        }
    }
    return dp[n] <= 0;
    // set<pair<double, int>> st = {{0, 1}};
    // vector<double> dp(n+1, 1e12);
    // dp[1] = 0;
    // while(!st.empty()) {
    //     int u = st.begin()->second;
    //     st.erase(st.begin());
    //     // cout<<pq.size()<<endl;
    //     for(auto [v, w] : graph[u]) {
    //         // cout<<v<<" "<<dp[v]<<" "<<u<<" "<<dp[u]<<" "<<w<<endl;
    //         if(dp[v] > dp[u] + w - mid) {
    //             if(st.count({dp[v], v})) {
    //                 st.erase({dp[v], v});
    //             }
    //             // cout<<"inside"<<endl;
    //             dp[v] = dp[u] + w - mid;
    //             // cout<<v<<" "<<dp[v]<<" "<<u<<" "<<dp[u]<<" "<<w<<endl;
    //             // cout<<endl;
    //             st.insert({dp[v], v});
    //             parent[v] = u;
    //         }
    //     }
    // }
    // // cout<<mid<<" "<<dp[n]<<endl;
    // return dp[n] <= 0;
}


void solve() {
    int n,m;
    cin>>n>>m;
    vector<vector<pair<int, int>>> graph(n+1);
    for(int i=0;i<m;i++) {
        int u, v, w;
        cin>>u>>v>>w;
        graph[u].push_back({v,w});
    }
    vector<int> parent(n+1);
    double low = 0, high = 101;
    // check(graph, n, 0.5, parent);
    for(int i=0;i<80;i++) {
        double mid = (low + high) / 2.0;
        if(check(graph, n, mid, parent)) {
            high = mid;
        }
        else {
            low = mid;
        }
    }
    // cout<<high<<endl;
    vector<int> ans = {n};
    int node = n;
    while(node != 1) {
        node = parent[node];
        ans.push_back(node);
    }
    reverse(ans.begin(), ans.end());
    cout<< ans.size()-1 << endl;
    for(auto& val : ans) {
        cout<<val<<" ";
    }
}