#include<bits/stdc++.h>
using namespace std;
void solve();
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
#ifndef ONLINE_JUDGE
    freopen("../../input.txt", "r", stdin);
    freopen("../../output.txt", "w", stdout);
#endif
    int t=1;
    while(t--)  solve();
    cerr << "time: " << (float)clock() / CLOCKS_PER_SEC << endl; return 0;
}

void solve() {
    int n;
    cin>>n;
    vector<int> a(n);
    int sum = 0;
    for(int i=0;i<n;i++) {
        cin>>a[i];
        sum += a[i];
    }
    vector<bool> dp(sum+1, false);
    dp[0] = true;
    for(int i=0;i<n;i++) {
        for(int j=sum;j>=a[i];j--) {
            if(dp[j-a[i]]) dp[j] = true;
        }
    }
    vector<int> ans;
    for(int i=1;i<=sum;i++) {
        if(dp[i]) ans.push_back(i);
    }
    cout<<ans.size()<<endl;
    for(auto& val : ans) {
        cout<<val<<" ";
    }
}