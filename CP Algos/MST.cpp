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


vector<int> dsu;
int parent(int x) {
    if(dsu[x] < 0) return x;
    return dsu[x] = parent(dsu[x]);
}

void merge(int a, int b) {
    int x = parent(a), y = parent(b);
    if(x != y) {
        if(dsu[x] < dsu[y]) {
            dsu[x] += dsu[y];
            dsu[y] = x;
        }
        else {
            dsu[y] += dsu[x];
            dsu[x] = y;
        }
    }
}

static bool compare(pair<int, pair<int,int>> &a, pair<int, pair<int,int>> &b) {
    return a.second.second < b.second.second;
}

void solve() {
    int n, m;
    cin>>n>>m;
    vector<pair<int,pair<int,int>>> edges(m);
    for(int i=0;i<m;i++) {
        int u, v, w;
        cin>>u>>v>>w;
        edges[i] = {u, {v, w}};
    }
    sort(edges.begin(), edges.end(), compare);//sorting wrt weight
    dsu = vector<int>(n+1, -1);
    int sum = 0;
    for(auto& edge : edges) {
        int u = edge.first;
        int v = edge.second.first;
        int w = edge.second.second;

        if(parent(u) != parent(v)) {
            merge(u, v);
            sum += w;
        }
    }
    for(int i=2;i<=n;i++) {
        if(parent(i) != parent(1)) {
            cout<<"IMPOSSIBLE"<<endl;
            return;
        }
    }
    cout<<sum<<endl;
}