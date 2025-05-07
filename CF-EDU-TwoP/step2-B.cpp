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
    int n,s;
    cin>>n>>s;
    vector<int> a(n);
    for(int i=0;i<n;i++) {
        cin>>a[i];
    }
    int l = 0, r = 0;
    int sum = 0;
    int ans = INT_MAX;
    while(r < n) {
        sum += a[r];
        while(sum >= s) {
            ans = min(ans, r-l+1);
            sum -= a[l];
            l++;
        }
        r++;
    }
    cout<<(ans == INT_MAX ? -1 : ans)<<endl;
}