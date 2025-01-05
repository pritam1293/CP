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
    // cin>>t;
    while(t--)  solve();
    cerr << "time: " << (float)clock() / CLOCKS_PER_SEC << endl; return 0;
}

void checkMoves(int row, int col, int &ans, int moves, vector<vector<bool>> &vis, vector<string> &mat, bool vertical) {
    if (mat[row][col] == 'G') {
        ans = min(moves, ans);
        return;
    }

    vis[row][col] = true;
    int n = mat.size(), m = mat[0].size();
    int nr, nc;
    if (vertical) {
        nr = row + 1;
        nc = col;
        if (nr >= 0 && nc >= 0 && nr < n && nc < m && !vis[nr][nc] && mat[nr][nc] != '#') {
            checkMoves(nr, nc, ans, moves + 1, vis, mat, !vertical);
        }

        nr = row - 1;
        nc = col;
        if (nr >= 0 && nc >= 0 && nr < n && nc < m && !vis[nr][nc] && mat[nr][nc] != '#') {
            checkMoves(nr, nc, ans, moves + 1, vis, mat, !vertical);
        }
    }
    else {
        nr = row;
        nc = col + 1;
        if (nr >= 0 && nc >= 0 && nr < n && nc < m && !vis[nr][nc] && mat[nr][nc] != '#') {
            checkMoves(nr, nc, ans, moves + 1, vis, mat, !vertical);
        }

        nr = row;
        nc = col - 1;
        if (nr >= 0 && nc >= 0 && nr < n && nc < m && !vis[nr][nc] && mat[nr][nc] != '#') {
            checkMoves(nr, nc, ans, moves + 1, vis, mat, !vertical);
        }
    }
    vis[row][col] = false; // Backtrack
}

void solve() {
    int n, m;
    cin >> n >> m;
    vector<string> mat(n);
    for (int i = 0; i < n; i++) {
        cin >> mat[i];
    }

    int x = -1, y = -1;
    bool found = false;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (mat[i][j] == 'S') {
                x = i;
                y = j;
                found = true;
                break;
            }
        }
        if (found) break;
    }

    int ans = INT_MAX;
    vector<vector<bool>> vis(n, vector<bool>(m, false));

    checkMoves(x, y, ans, 0, vis, mat, false); // vertical = false
    checkMoves(x, y, ans, 0, vis, mat, true);  // vertical = true

    if (ans == INT_MAX) {
        cout << "-1" << endl; // No path found
    }
    else {
        cout << ans << endl;
    }
}