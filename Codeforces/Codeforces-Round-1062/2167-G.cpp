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

void solve() {
    int n;
    cin>>n;
    vector<int> a(n), c(n);
    set<int> st;
    for (int i = 0; i < n; i++) {
        cin>>a[i];
        st.insert(a[i]);
    }
    for (int i = 0; i < n; i++) {
        cin>>c[i];
    }
    vector<int> u(st.begin(), st.end());
    int k = u.size();
    vector<int> dp(k, 0);
    int sum = 0;

    for (int i = 0; i < n; i++) {
        sum += c[i];
        vector<int> temp(k, 0);
        int maxm = 0;
        for (int j = 0; j < k; j++) {
            maxm = max(maxm, dp[j]);
            int curr = (a[i] == u[j]) ? c[i] : 0;
            temp[j] = maxm + curr;
        }
        dp = temp;
    }
    int m = 0;
    for(auto& e : dp) m = max(m, e);
    cout << sum - m << endl;
}