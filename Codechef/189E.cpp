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
    cin>>t;
    while(t--)  solve();
    cerr << "time: " << (float)clock() / CLOCKS_PER_SEC << endl; return 0;
}

void solve() {
    int n, k;
    cin>>n>>k;
    vector<vector<int>> pos(k+1); 
    for(int i=1;i<=n;i++) {
        int x;
        cin>>x;
        pos[x].push_back(i);  
        pos[0].push_back(i);
    }
    vector<int> ans(n+1), dp(n+1);
    for(int i = k-1; i >= 0; i--) {
        int ptr = 0;
        for(int x : pos[i]) {
            while(ptr+1 < pos[i+1].size() && pos[i+1][ptr+1] < x) ptr++;

            int y = pos[i+1][ptr];
            int res = dp[y] + abs(x - y);

            if(ptr+1 < pos[i+1].size()) {
                y = pos[i+1][ptr+1];
                res = min(res, dp[y] + abs(x - y));
            }
            if(i == 0) ans[x] = res;
            else dp[x] = res;
        }
    }
    for(int i=1;i<=n;i++) {
        cout<<ans[i]<<" ";
    }
    cout<<endl;
}