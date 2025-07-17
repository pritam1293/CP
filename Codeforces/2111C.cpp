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
    for(int i=0;i<n;i++) {
        cin>>a[i];
    }
    int ans = 1e17;
    int i = 0;
    while(i < n) {
        int left = i;
        int curr = a[i] * 1LL * left;
        int j = i;
        while(i < n && a[i] == a[j]) i++;
        if(i < n) {
            int right = n-i;
            curr += a[i-1] * 1LL * right;
        }
        ans = min(ans, curr);
    }
    cout<<ans<<endl;
}