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

int ans = 0;
bool vis[20][20];
int n,m;

void dfs(int i, int j, vector<vector<int>> &mat) {
    if(i == n) {
        int score = 0;
        for(int x=0;x<n;x++) {
            for(int y=0;y<m;y++) {
                if(!vis[x][y]) {
                    score ^= mat[x][y];
                }
            }
        }
        ans = max(ans, score);
        return;
    }

    int ni, nj;
    
    if (j+1 < m) { //same row, next col
        ni = i;
        nj = j+1;
    } 
    else {//1st col, next row
        ni = i+1;
        nj = 0;
    }

    if(vis[i][j]) {
        dfs(ni, nj, mat);
        return;
    }

    dfs(ni, nj, mat);

    if(j+1 < m && !vis[i][j+1]) {
        vis[i][j] = true;
        vis[i][j+1] = true;
        dfs(ni, nj, mat);
        vis[i][j] = false;
        vis[i][j+1] = false;
    }

    if(i+1 < n && !vis[i+1][j]) {
        vis[i][j] = true;
        vis[i+1][j] = true;
        dfs(ni, nj, mat);
        vis[i][j] = false;
        vis[i+1][j] = false;
    }
}


void solve() {
    cin>>n>>m;
    vector<vector<int>> mat(n, vector<int>(m));
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            cin>>mat[i][j];
        }
    }
    dfs(0, 0, mat);
    cout<<ans<<endl;
}