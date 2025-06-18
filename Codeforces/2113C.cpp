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
    cin>>t;
    while(t--)  solve();
    cerr << "time: " << (float)clock() / CLOCKS_PER_SEC << endl; return 0;
}

void solve() {
    int n, m, k;
    cin>>n>>m>>k;
    k--;
    vector<string> mine(n);
    int gold = 0;
    for(int i=0;i<n;i++) {
        cin>>mine[i];
        for(int j=0;j<m;j++) {
            gold += mine[i][j] == 'g';
        }
    }
    // cout<<gold<<endl;
    vector<vector<int>> presum(n+1, vector<int>(m+1));
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            presum[i+1][j+1] = presum[i+1][j] + presum[i][j+1] - presum[i][j] + (mine[i][j] == 'g');
        }
    }
    int cnt = gold;
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            if(mine[i][j] == '.') {
                int top = max(0, i-k);
                int bottom = min(n, i+k+1);
                int left = max(0, j-k);
                int right = min(m, j+k+1);

                cnt = min(cnt, presum[bottom][right] - presum[bottom][left] - presum[top][right] + presum[top][left]);
            }
        }
    }
    cout<< gold - cnt <<endl;
}