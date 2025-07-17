#include<bits/stdc++.h>
using namespace std;
void solve();
int main() {
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
    int n, k;
    cin>>n>>k;
    vector<int> a(n);
    int mx = 0, mn = 100;
    for(int i=0;i<n;i++) {
        cin>>a[i];
        mx = max(mx, a[i]);
        mn = min(mn, a[i]);
    }
    int ans = 0;
    if(k >= mn && k <= mx) {
        ans += mx - mn;
        if(k - mn >= mx -k) {
            ans += (mx-k);
        }
        else {
            ans += k-mn;
        }
    }
    else if(k <= mn) {
        ans = mx-k;
    }
    else ans = k-mn;
    cout<<ans<<endl;
}