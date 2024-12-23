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

const int dir[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

void possible(int x,int y,int k,vector<vector<char>> &grid,vector<vector<bool>> &vis,int &cnt) {
	if(k == 0) {
		cnt++;
		return;
	}
	vis[x][y] = true;
	for (int d=0;d<4;d++) {
        int nx = x + dir[d][0];
        int ny = y + dir[d][1];

        if (nx >= 0 && nx < grid.size() && ny >= 0 && ny < grid[0].size() && grid[nx][ny] == '.' && !vis[nx][ny]) {
            possible(nx, ny, k - 1, grid, vis, cnt);
        }
    }
    vis[x][y] = false;
}

void solve() {
    int h,w,k;
    cin>>h>>w>>k;
    vector<vector<char>> grid(h,vector<char>(w));
    for(int i=0;i<h;i++) {
    	for(int j=0;j<w;j++) {
    		cin>>grid[i][j];
    	}
    }
    int cnt = 0;
    vector<vector<bool>> vis(h,vector<bool>(w,false));
    for(int i=0;i<h;i++) {
    	for(int j=0;j<w;j++) {
    		if(grid[i][j] == '.') {
    			possible(i,j,k,grid,vis,cnt);
    		}
    	}
    }
    cout<<cnt;
}
