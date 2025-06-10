#include<bits/stdc++.h>
using namespace std;
void solve();
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int t=1;
    cin>>t;
    while(t--)  solve();
    cerr << "time: " << (float)clock() / CLOCKS_PER_SEC << endl; return 0;
}

vector<int> dsu;
vector<int> minw;
int parent(int x) {
    if(dsu[x] < 0) return x;
    return dsu[x] = parent(dsu[x]);
}

void merge(int a, int b, int w) {
    int x = parent(a), y = parent(b);
    if(x != y) {
        if(dsu[x] < dsu[y]) {
            dsu[x] += dsu[y];
            dsu[y] = x;
            int temp = minw[x];
            minw[x] = min({minw[x], minw[y], w});
            minw[y] = min({temp, minw[y], w});
        }
        else {
            dsu[y] += dsu[x];
            dsu[x] = y;
            int temp = minw[y];
            minw[y] = min({minw[x], minw[y], w});
            minw[x] = min({minw[x], temp, w});
        }
    }
    else {
        minw[x] = min(minw[x], w);
    }
}

void solve() {
    int n, m;
    cin>>n>>m;
    vector<vector<int>> edges(m);
    for(int i=0;i<m;i++) {
        int u, v, w;
        cin>>u>>v>>w;
        edges[i] = {w, u, v};
    }
    sort(edges.begin(), edges.end());
    dsu = vector<int>(n+1, -1);
    minw = vector<int>(n+1, 1e9);
    int ans = INT_MAX;
    for(auto& edge : edges) {
        int w = edge[0];
        int u = edge[1];
        int v = edge[2];
        if(parent(u) != parent(v)) {
            merge(u, v, w);
        }
        parent(u);
        parent(v);
        if(parent(n) == parent(1)) {
            ans = min(ans, w + minw[n]);
        }
    }
    cout<<ans<<endl;
}
