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
    cin>>t;
    while(t--)  solve();
    cerr << "time: " << (float)clock() / CLOCKS_PER_SEC << endl; return 0;
}

void dfs(int node, int parent, int pos, int neg, vector<vector<int>> &tree, vector<int> &a, vector<int> &ans) {
    ans[node] = a[node] + pos;
    int temp = neg;
    neg = max(0ll, a[node] + pos);
    pos = max(0ll, -a[node] + temp);

    for(auto& child : tree[node]) {
        if(child != parent) dfs(child, node, pos, neg,tree, a, ans);
    }
}

void solve() {
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++) {
        cin>>a[i];
    }
    vector<vector<int>> tree(n);
    for(int i=1;i<n;i++) {
        int u, v;
        cin>>u>>v;
        u--;v--;
        tree[u].push_back(v);
        tree[v].push_back(u);
    }
    vector<int> ans(n);
    dfs(0, -1, 0, 0, tree, a, ans);
    for(auto& val : ans) {
        cout<<val<<" ";
    }
    cout<<endl;
}