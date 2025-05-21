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

int n, m;
vector<int> drow = {1, 0, -1, 0};
vector<int> dcol = {0, 1, 0, -1};

void backtrack(string &ans, int row, int col, vector<vector<char>> &steps, vector<string> &grid) {
    if(grid[row][col] != 'A') {
        char ch = steps[row][col];
        ans += ch;
        if(ch == 'D') backtrack(ans, row-1, col, steps, grid);
        else if(ch == 'U') backtrack(ans, row+1, col, steps, grid);
        else if(ch == 'L') backtrack(ans, row, col+1, steps, grid);
        else if(ch == 'R') backtrack(ans, row, col-1, steps, grid);
    }
}

void solve() {
    cin>>n>>m;
    vector<string> grid(n);
    vector<vector<bool>> vis(n, vector<bool>(m, false));
    vector<vector<int>> dist(n, vector<int>(m, INT_MAX));
    vector<vector<char>> steps(n, vector<char>(m));
    queue<pair<int, pair<int,int>>> q;
    pair<int, int> start;
    for(int i=0;i<n;i++) {
        cin>>grid[i];
        for(int j=0;j<m;j++) {
            if(grid[i][j] == 'M') {
                q.push({0, {i, j}});
                vis[i][j] = true;
                dist[i][j] = 0;
            }
            else if(grid[i][j] == 'A') start = {i, j};
        }
    }
    while(!q.empty()) {
        int d = q.front().first;
        int row = q.front().second.first;
        int col = q.front().second.second;
        q.pop();

        for(int i=0;i<4;i++) {
            int nr = row + drow[i];
            int nc = col + dcol[i];

            if(nr >= 0 && nc >= 0 && nr < n && nc < m && grid[nr][nc] != '#' && !vis[nr][nc]) {
                if(dist[nr][nc] > d+1) {
                    dist[nr][nc] = d+1;
                    vis[nr][nc] = true;
                    q.push({d+1, {nr, nc}});
                }
            }
        }
    }
    q.push({0, start});
    bool flag = false;
    int row, col;
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            vis[i][j] = false;
        }
    }
    vis[start.first][start.second] = true;
    while(!q.empty()) {
        int d = q.front().first;
        row = q.front().second.first;
        col = q.front().second.second;
        q.pop();
        if(row == 0 || row == n-1 || col == 0 || col == m-1) {
            flag = true;
            break;
        }

        for(int i=0;i<4;i++) {
            int nr = row + drow[i];
            int nc = col + dcol[i];
            if(nr >= 0 && nc >= 0 && nr < n && nc < m && grid[nr][nc] != '#' && !vis[nr][nc]) {
                if(d+1 < dist[nr][nc]) {
                    q.push({d+1, {nr, nc}});
                    vis[nr][nc] = true;
                    if(i == 0) steps[nr][nc] = 'D';
                    else if(i == 1) steps[nr][nc] = 'R';
                    else if(i == 2) steps[nr][nc] = 'U';
                    else if(i == 3) steps[nr][nc] = 'L';
                }
            }
        }
    }
    if(flag) {
        cout<<"YES"<<endl;
        string ans;
        backtrack(ans, row, col, steps, grid);
        int len = ans.size();
        cout<<len<<endl;
        for(int i=len-1;i>=0;i--) {
            cout<<ans[i];
        }
    }
    else {
        cout<<"NO"<<endl;
    }
}