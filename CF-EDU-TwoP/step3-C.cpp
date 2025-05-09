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
    while(t--)  solve();
    cerr << "time: " << (float)clock() / CLOCKS_PER_SEC << endl; return 0;
}

void solve() {
    int n,d;
    cin>>n>>d;
    vector<int> a(n);
    for(int i=0;i<n;i++) cin>>a[i];
    int ans = 0;
    int l = 0, r = 0;
    while(r < n) {
        while(r < n && a[r] - a[l] <= d) r++;
        ans += n-r;
        l++;
    }
    cout<<ans<<endl;
}