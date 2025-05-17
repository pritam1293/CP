#include<bits/stdc++.h>
using namespace std;
void solve();
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
#ifndef ONLINE_JUDGE
    freopen("../../2.in", "r", stdin);
    // freopen("../../input.txt", "r", stdin);
    freopen("../../output.txt", "w", stdout);
#endif
    int t=1;
    while(t--)  solve();
    cerr << "time: " << (float)clock() / CLOCKS_PER_SEC << endl; return 0;
}

void solve() {
    int n;
    cin>>n;
    vector<string> grid(n);
    for(int i=0;i<n;i++) {
        cin>>grid[i];
    }
    vector<vector<bool>> vis(n, vector<bool>(n, false));
    vis[0][0] = true;
    string ans;
    vector<pair<int,int>> curr = {{0, 0}};
    
    for(int j = 0; j < 2*n -1; j++) {
        char minChar = 'Z';
        for(auto& [r, c] : curr) {
            minChar = min(minChar, grid[r][c]);
        }
        ans += minChar;
        vector<pair<int,int>> next;

        for(auto& [r, c] : curr) {
            if(grid[r][c] != minChar) continue;

            if(r+1 < n && !vis[r+1][c]) {
                next.push_back({r+1, c});
                vis[r+1][c] = true;
            }

            if(c+1 < n && !vis[r][c+1]) {
                next.push_back({r, c+1});
                vis[r][c+1] = true;
            }
        }
        curr = next;
    }
    
    cout<<ans<<endl;
}