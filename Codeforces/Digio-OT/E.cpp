#include<bits/stdc++.h>
using namespace std;
#define int long long
void solve();
int32_t main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
#ifndef ONLINE_JUDGE
    freopen("../../input.txt", "r", stdin);
    freopen("../../output.txt", "w", stdout);
#endif
    int t=1;
    cin>>t;
    while(t--)  solve();
    cerr << "time: " << (float)clock() / CLOCKS_PER_SEC << endl; return 0;
}

map<pair<int, int>, int> mpp;
vector<int> a;

int dp(int i, int j) {
    if (i > j) return 0;
    if (i == j) return a[i];
    if (mpp.count({i, j})) return mpp[{i, j}];

    int ans = -2e18; 

    ans = max(ans, dp(i + 1, j));
    ans = max(ans, dp(i, j - 1));
    for (int k = i + 1; k < j; ++k) {
        ans = max(ans, dp(i, k - 1) + dp(k + 1, j));
    }
    return mpp[{i, j}] = ans;
}

void solve() {
    int n;
    cin >> n;
    a = vector<int>(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    mpp.clear();
    if (n == 1) {
        cout<<a[0]<<endl;
        return;
    }
    cout<<dp(0, n-1)<<endl;
}