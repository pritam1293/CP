#include<bits/stdc++.h>
using namespace std;
#define int long long
void solve();
int32_t main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
#ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
#endif
    int t=1;
    while(t--)  solve();
    cerr << "time: " << (float)clock() / CLOCKS_PER_SEC << endl; return 0;
}

int ans = 0;

int dfs(int node, int parent, vector<int> &a, vector<vector<pair<int,int>>> &tree) {
    int charge = a[node];
    for(auto& [child, w] : tree[node]) {
        if(child == parent) continue;
        int child_charge = dfs(child, node, a, tree);
        charge += child_charge;
        ans += 1LL * abs(child_charge) * w;
    }
    return charge;
}

void solve() {
    int n;
    cin>>n;
    vector<int> a(n+1);
    for(int i=1;i<=n;i++) {
        cin>>a[i];
    }
    vector<vector<pair<int,int>>> tree(n+1);
    for(int i=1;i<n;i++) {
        int u, v, w;
        cin>>u>>v>>w;
        tree[u].push_back({v, w});
        tree[v].push_back({u, w});
    }
    dfs(1, -1, a, tree);
    cout<<ans<<endl;
}