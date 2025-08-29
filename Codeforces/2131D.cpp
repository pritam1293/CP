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

void solve() {
    int n;
    cin>>n;
    vector<vector<int>> tree(n);
    vector<int> deg(n);
    for(int i = 1; i < n; i++) {
        int u, v;
        cin>>u>>v;
        u--;v--;
        tree[u].push_back(v);
        tree[v].push_back(u);
        deg[u]++;
        deg[v]++;
    }
    if(n <= 3) {
        cout<<0<<endl;
    }
    else {
        int cnt = 0;
        for(int i = 0; i < n; i++) {
            if(deg[i] == 1) cnt++;
        }
        int mx = 0;
        for(int i = 0; i < n; i++) {
            int c = 0;
            for(auto& j : tree[i]) {
                if(deg[j] == 1) c++;
            }
            mx = max(mx, c);
        }
        cout<<cnt-mx<<endl;
    }
}