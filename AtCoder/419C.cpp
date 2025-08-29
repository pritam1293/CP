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
    // cin>>t;
    while(t--)  solve();
    cerr << "time: " << (float)clock() / CLOCKS_PER_SEC << endl; return 0;
}

void solve() {
    int n;
    cin>>n;
    vector<int> r(n), c(n);
    for(int i = 0; i < n; i++) {
        cin>>r[i]>>c[i];
    }
    sort(r.begin(), r.end());
    sort(c.begin(), c.end());
    int dr = r.back() - r[0], dc = c.back() - c[0];
    cout<< (max(dr, dc) + 1) / 2 <<endl;
}