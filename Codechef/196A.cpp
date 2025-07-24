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
    vector<int> a(n), b(n);
    for(int i = 0; i < n; i++) {
        cin>>a[i];
    }
    int mx = 0;
    for(int i = 0; i < n; i++) {
        cin>>b[i];
        mx = max(mx, b[i]);
    }
    int ans = 0;
    for(int c = 0; c <= mx; c++) {
        int sum = -c;
        for(int i = 0; i < n; i++) {
            if(b[i] <= c) sum += max(0ll, a[i]);
        }
        ans = max(ans, sum);
    }
    cout<<ans<<endl;
}