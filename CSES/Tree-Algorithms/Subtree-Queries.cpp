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

vector<int> val, euler, in, out, seg;
vector<vector<int>> tree;
int timer = 0;

void dfs(int node, int parent) {
    in[node] = ++timer;
    euler[timer] = val[node];
    for(auto& child : tree[node]) {
        if(child != parent) dfs(child, node);
    }
    out[node] = timer;
}

void build(int low, int high, int pos) {
    if(low == high) {
        seg[pos] = euler[low]; 
    }
    else {
        int mid = (low + high) / 2;
        build(low, mid, 2*pos);
        build(mid+1, high, 2*pos + 1);
        seg[pos] = seg[2*pos] + seg[2*pos + 1];
    }
}

void update(int low, int high, int pos, int t, int val) {
    if(low == high) {
        seg[pos] = val;
        return;
    }
    int mid = (low + high) / 2;
    if(t <= mid) update(low, mid, 2*pos, t, val);
    else update(mid+1, high, 2*pos + 1, t, val);
    seg[pos] = seg[2*pos] + seg[2*pos + 1];
}

int query(int low, int high, int ql, int qr, int pos) {
    if(ql > high || qr < low) return 0;
    if(low >= ql && high <= qr) {
        return seg[pos];
    }
    int mid = (low + high) / 2;
    return query(low, mid, ql, qr, 2*pos) + query(mid + 1, high, ql, qr, 2*pos + 1);
}

void solve() {
    int n, q;
    cin>>n>>q;
    val = vector<int>(n+1);
    for(int i = 1; i <=n; i++) {
        cin>>val[i];
    }
    tree = vector<vector<int>>(n+1);
    for(int i = 1; i < n; i++) {
        int u, v;
        cin>>u>>v;
        tree[u].push_back(v);
        tree[v].push_back(u);
    }
    euler = vector<int>(n+1);
    in = vector<int>(n+1);
    out = vector<int>(n+1);
    seg = vector<int>(4*n + 4);
    dfs(1, 0);
    build(1, n, 1);
    while(q--) {
        int t;
        cin>>t;
        if(t == 1) {
            int node, val;
            cin>>node>>val;
            update(1, n, 1, in[node], val);
        }
        else {
            int node;
            cin>>node;
            cout<<query(1, n, in[node], out[node], 1)<<endl;
        }
    }
}