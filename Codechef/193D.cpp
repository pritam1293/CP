#include<bits/stdc++.h>
using namespace std;
void solve();
int main() {
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
    vector<int> degree(n+1);
    int deg = 0;
    for(int i = 1; i < n; i++) {
        int u, v;
        cin>>u>>v;
        degree[u]++;
        degree[v]++;
        deg = max(deg, degree[u]);
        deg = max(deg, degree[v]);
    }
    if(deg <= 2) {
        cout<< 2*n - 1 <<endl;
    }
    else {
        cout<< n+1 <<endl;
    }
}