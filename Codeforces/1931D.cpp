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
    int n, x, y;
    cin>>n>>x>>y;
    vector<int> a(n);
    for(int i = 0; i < n; i++) {
        cin>>a[i];
    }
    map<pair<int,int>, int> mp;
    int ans = 0;
    for(auto& e : a) {
        int xx = (x - (e % x)) % x;
        int yy = e % y;
        ans += mp[{xx, yy}];
        mp[{e % x, yy}]++;
    }
    cout<<ans<<endl;
}