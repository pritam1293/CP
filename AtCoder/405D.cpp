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

void solve() {
    int n, m;
    cin>>n>>m;
    vector<string> a(n);
    for(int i=0;i<n;i++) {
        cin>>a[i];
    }
    vector<string> ans(n);
    for(int i=0;i<n;i++) {
        cin>>ans[i];
    }
    vector<vector<bool>> vis(n, vector<bool>(m, false));
    queue<pair<int,int>> q;//row and col
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            if(a[i][j] == 'E') {
                q.push({i, j});
                vis[i][j] = true;
            }
        }
    }

    int dx[4] = {-1, 1, 0, 0};
    int dy[4] = {0, 0, -1, 1};
    char darrrow[4] = {'v', '^', '>', '<'};

    while(!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for(int i=0;i<4;i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if(nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
            if(a[nx][ny] != '.' || vis[nx][ny]) continue;

            vis[nx][ny] = true;
            a[nx][ny] = darrrow[i];

            q.push({nx, ny});
        }
    }

    for(auto& s : a) {
        cout<<s<<endl;
    }
}