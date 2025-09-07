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

void solve() {
    int n, m;
    cin>>n>>m;
    vector<string> grid(n);
    for(int i = 0; i < n; i++) {
        cin>>grid[i];
    }
    vector<int> dx = {1, -1, 0, 0};
    vector<int> dy = {0, 0, 1, -1};
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(grid[i][j] == '#') {
                int cnt = 0;
                for(int d = 0; d < 4; d++) {
                    int x = i + dx[d];
                    int y = j + dy[d];
                    if(x >= 0 && y >= 0 && x < n && y < m && grid[x][y] == '#') cnt++;
                }
                if(cnt != 2 && cnt != 4) {
                    cout<<"No";
                    return;
                }
            }
        }
    }
    cout<<"Yes"<<endl;
}