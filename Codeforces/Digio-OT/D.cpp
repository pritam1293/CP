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
    vector<int> a(n);
    for(int i = 0; i < n; i++) {
        cin>>a[i];
    }
    bool neg = true;
    for(int i = 0; i < n; i++) {
        if(a[i] >= 0) neg = false;
    }
    if(neg) {
        int mx = a[0];
        for(auto& e : a) {
            mx = max(mx, e);
        }
        cout<<mx<<endl;
        return;
    }
    int ans1 = 0, ans2 = 0;
    for(int i = 0; i < n; i++) {
        if(i & 1) ans1 += max(0ll, a[i]);
        else ans2 += max(0ll, a[i]);
    }
    cout<<max(ans1, ans2)<<endl;

}