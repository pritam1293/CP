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
    for(int i= 0; i < n; i++) {
        cin>>a[i];
    }
    sort(a.begin(), a.end());
    int ans = -1e10;
    for(int i = 0; i < n; i += 2) {
        ans = max(ans, a[i+1] - a[i]);
    }
    cout<<ans<<endl;
}