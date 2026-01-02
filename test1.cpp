#include<bits/stdc++.h>
using namespace std;
#define int long long
void solve();
int32_t main() {
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

vector<vector<int>> tree;
vector<int> cnt;
long long ans = 0;

vector<int> dfs(int node, int parent, vector<int> &group) {
    vector<int> curr(21);
    curr[group[node]]++;

    for (auto child : tree[node]) {
        if (child == parent) continue;
        vector<int> sub = dfs(child, node, group);
        for (int i = 1; i <= 20; ++i) {
            ans += 1LL * sub[i] * (cnt[i] - sub[i]);
            curr[i] += sub[i];
        }
    }
    return curr;
}

long long interactionCost(int n, vector<vector<int>> &edges, vector<int> &group) {
    ans = 0;
    tree = vector<vector<int>>(n);
    for(auto& e : edges) {
        tree[e[0]].push_back(e[1]);
        tree[e[1]].push_back(e[0]);
    }
    cnt = vector<int>(21);
    for(auto& g : group) {
        cnt[g]++;
    }
    dfs(0, -1, group);
    return ans;
}

void solve() {
    int n = 3;
    vector<vector<int>> edges = {{0, 1}, {1, 2}};
    vector<int> group = {1, 1, 1};
    cout<<interactionCost(n, edges, group)<<endl;
    n = 3;
    edges = {{0, 1}, {1, 2}};
    group = {3, 2, 3};
    cout<<interactionCost(n, edges, group)<<endl;
    n = 4;
    edges = {{0, 1}, {0, 2}, {0, 3}};
    group = {1, 1, 4, 4};
    cout<<interactionCost(n, edges, group)<<endl;
    n = 2;
    edges = {{0, 1}};
    group = {9, 8};
    cout<<interactionCost(n, edges, group)<<endl;
}