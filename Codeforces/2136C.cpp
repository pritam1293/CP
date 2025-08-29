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
    int n;
    cin>>n;
    vector<int> a(n);
    map<int, vector<int>> pos;
    for(int i = 0; i < n; i++) {
        cin>>a[i];
        pos[a[i]].push_back(i);
    }
    vector<int> dp(n+1);
    map<int,int> mp;//freq
    for(int i = 1; i <= n; i++) {
        dp[i] = dp[i-1];
        int val = a[i-1];
        mp[val]++;
        if(mp[val] >= val) {
            int idx = pos[val][mp[val] - val];
            dp[i] = max(dp[i], dp[idx] + val);
        }
    }
    cout<<dp[n]<<endl;
}