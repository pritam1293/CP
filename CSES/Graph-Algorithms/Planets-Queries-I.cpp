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

void solve() {
    int n, q;
    cin>>n>>q;
    vector<vector<int>> parent(n+1, vector<int>(30));
    // int parent[n+1][30];
    for(int i=1;i<=n;i++) {
        cin>>parent[i][0];
    }
    for(int d=1;d<30;d++) {
        for(int i=1;i<=n;i++) {
            parent[i][d] = parent[parent[i][d-1]][d-1];
        }
    }
    while(q--) {
        int node, d;
        cin>>node>>d;
        for(int i=0;i<30;i++) {
            if(1 & (d >> i)) node = parent[node][i];
        }
        cout<<node<<"\n";
    }
}