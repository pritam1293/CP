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

int mod = 1e9+7;
vector<int> lens;
int lca;

void dfs(int node, int parent, int len, vector<vector<int>> &tree) {
    if(tree[node].size() > 2) {
        lca = len;
    }
    bool flag = true;
    for(auto& child : tree[node]) {
        if(child != parent) {
            dfs(child, node, len+1 , tree);
            flag = false;
        }
    }
    if(flag) lens.push_back(len);
}

void solve() {
    lens.clear();
    lca = 1;
    int n;
    cin>>n;
    vector<vector<int>> tree(n+1);
    for(int i=1;i<n;i++) {
        int u,v;
        cin>>u>>v;
        tree[u].push_back(v);
        tree[v].push_back(u);
    }
    // tree[1].push_back(0);
    dfs(1, 0, 1, tree);
    vector<int> power(n+1, 1);
    for(int i=1;i<=n;i++) {
        power[i] = (2 * power[i-1]) % mod;
    }
    int len = lens.size();
    if(len > 2) {
        cout<<"0"<<endl;
    }
    else if(len == 1) {
        cout<<power[n]<<endl;
    }
    else {
        int diff = abs(lens[0] - lens[1]);
        int x = lca + diff;
        if(diff) {
            cout<<(power[x] + power[x-1]) % mod <<endl;
        }
        else {
            cout<<(power[x] + power[x]) % mod <<endl;
        }
    }
}