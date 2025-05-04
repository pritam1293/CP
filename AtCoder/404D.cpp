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
    while(t--)  solve();
    cerr << "time: " << (float)clock() / CLOCKS_PER_SEC << endl; return 0;
}

long long ans = 0

void solve() {
    int n, m;
    cin>>n>>m;
    vector<long long> c(n);  
    for(int i=0;i<n;i++) {
        cin>>c[i];
    }
    vector<vector<int>> zoo(n);
    for(int i=0;i<m;i++) {
        int k;
        cin>>k;
        for(int j=0;j<k;j++) {
            int x;
            cin>>x;
            zoo[x-1].push_back(i);
        }
    }
    int limit = 1 << 20;
    for(int i=1;i<=limit;i++) {

    }
}