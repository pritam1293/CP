#include<bits/stdc++.h>
using namespace std;
void solve();
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
#ifndef ONLINE_JUDGE
    freopen("../../input.txt", "r", stdin);
    freopen("../../output.txt", "w", stdout);
#endif
    int t=1;
    while(t--)  solve();
    cerr << "time: " << (float)clock() / CLOCKS_PER_SEC << endl; return 0;
}

vector<int> cnt;

int dfs(int node, int parent, vector<vector<int>> &tree) {
    int count = cnt[node];
    for(auto& child : tree[node]) {
        if(child == parent) continue;
        count += 1 + dfs(child, node, tree);
    }
    return cnt[node] = count;
}

void solve() {
    int n;
    cin>>n;
    vector<vector<int>> tree(n+1);
    for(int i=2;i<=n;i++) {
        int v;
        cin>>v;
        tree[i].push_back(v);
        tree[v].push_back(i);
    }
    cnt = vector<int>(n+1);
    dfs(1, -1, tree);
    for(int i=1;i<=n;i++) {
        cout<<cnt[i]<<" ";
    }
}