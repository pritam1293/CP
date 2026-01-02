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
    int n, k;
    cin>>n>>k;
    vector<int> a(n), b(n);
    for(int i = 0; i < n; i++) {
        cin>>a[i];
    }
    for(int i = 0; i < n; i++) {
        cin>>b[i];
    }
    k %= 2;
    vector<int> left(n), right(n);
    left[0] = a[0];
    for(int i = 1; i < n; i++) {
        left[i] = max(0ll, left[i-1]) + a[i];
    }
    right[n-1] = a[n-1];
    for(int i = n-2; i >= 0; i--) {
        right[i] = max(0ll, right[i+1]) + a[i];
    }
    int ans = -1e18;
    if(k == 0ll) {
        for(auto& e : left) {
            ans = max(e, ans);
        }
    }
    else {
        for(int i = 0; i < n; i++) {
            ans = max(ans, left[i] + right[i] - a[i] + b[i]);
        }
    }
    cout<<ans<<endl;
}