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

int mod = 1e9 + 7;

void solve() {
    int n, m;
    cin>>n>>m;
    vector<vector<int>> graph(n+1);
    vector<int> indegree(n+1);
    for(int i=0;i<m;i++) {
        int u,v;
        cin>>u>>v;
        graph[u].push_back(v);
        indegree[v]++;
    }
    vector<int> topo;
    queue<int> q;
    for(int i=1;i<=n;i++) {
        if(indegree[i] == 0) q.push(i);
    }

    while(!q.empty()) {
        int node = q.front();
        q.pop();
        topo.push_back(node);

        for(auto& child : graph[node]) {
            indegree[child]--;
            if(indegree[child] == 0) q.push(child);
        }
    }
    vector<int> dp(n+1);
    dp[n] = 1;
    for(int i = topo.size()-1;i>=0;i--) {
        int node = topo[i];
        for(auto& child : graph[node]) {
            dp[node] = (dp[node] + dp[child]) % mod;
        }
    }
    cout<<dp[1]<<endl;
} 