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
    while(t--)  solve();
    cerr << "time: " << (float)clock() / CLOCKS_PER_SEC << endl; return 0;
}

void solve() {
    vector<string> grid = {"LS", "RL"};
    int k = 4;
    int n = grid.size();
    int m = grid[0].size();
    queue<vector<int>> q;
    set<pair<int,int>> st;
    vector<vector<bool>> vis(n, vector<bool>(m, false));
    for(int i = 0;i<n;i++) {
        for(int j=0;j<m;j++) {
            if(grid[i][j] == 'L') {
                st.insert({i, j});
            }
            else if (grid[i][j] == 'S') {
                q.push({i ,j, k, 0});
                vis[i][j] = true;
            }
        }
    }
    cout<<st.size();
    int dx[4] = {1, 0, -1, 0};
    int dy[4] = {0, 1, 0, -1};

    while(!q.empty()) {
        int x = q.front()[0];
        int y = q.front()[1];
        int en = q.front()[2];
        int cost = q.front()[3];
        if(st.empty()) {
            cout<<cost<<endl;
            return;
        }
        q.pop();
        if(en == -1) {
            cout<<"-1"<<endl;
            return;
        }
        for(int i=0;i<4;i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx >= 0 && ny >= 0 && nx < n && ny < m && grid[nx][ny] != 'X' && !vis[nx][ny]) {
                vis[nx][ny] = true;
                if(grid[nx][ny] == 'L') st.erase({nx, ny});
                if(st.empty()) {
                    cout<< cost + 1 <<endl;
                    return;
                }
                if(grid[nx][ny] == 'R') q.push({nx, ny, k, cost+1});
                else q.push({nx, ny, en-1, cost+1});
            }
        }
    }
    cout<<"-1"<<endl;
}
