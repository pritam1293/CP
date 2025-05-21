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

vector<int> drow = {1, 0, -1, 0};
vector<int> dcol = {0, 1, 0, -1};
int n, m;

void dfs(int row, int col, vector<vector<bool>> &vis, vector<string> &grid) {
    vis[row][col] = true;
    for(int i=0;i<4;i++) {
        int nr = row + drow[i];
        int nc = col + dcol[i];
        if(nr >= 0 && nc >= 0 && nr < n && nc < m && !vis[nr][nc]) {
            dfs(nr, nc, vis, grid);
        }
    }
}

void solve() {
    cin>>n>>m;
    vector<string> grid(n);
    for(int i=0;i<n;i++) {
        cin>>grid[i];
    }
    int cnt = 0;
    vector<vector<bool>> vis(n, vector<bool>(m, false));
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            if(grid[i][j] == '#') vis[i][j] = true;
        }
    }
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            if(!vis[i][j]) {
                dfs(i, j, vis, grid);
                cnt++;
            }
        }
    }
    cout<<cnt<<endl;
}