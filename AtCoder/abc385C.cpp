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

int longestAP(vector<int>& arr , int n) {
    if (n <= 2) {
        return n;
    }

    int longest = 2;
    vector<map<int, int>> dp(n);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i; j++) {

            int diff = arr[i] - arr[j];
            dp[i][diff] = dp[j].count(diff) ? dp[j][diff] + 1 : 2;
            longest = max(longest, dp[i][diff]);
        }
    }

    return longest;
}

void solve() {
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++) {
        cin>>a[i];
    }
    
    map<int,vector<int>> idx;
    for(int i=0;i<n;i++) {
        idx[a[i]].push_back(i);
    }

    int ans = 0;
    for(auto it : idx) {
        vector<int> arr = it.second;
        int cnt = longestAP(arr,arr.size());
        ans = max(ans , cnt);
    }
    cout<<ans<<endl;
}
