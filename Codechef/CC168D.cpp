#include<bits/stdc++.h>
using namespace std;
void solve();
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int t=1;
    cin>>t;
    while(t--)  solve();
    cerr << "time: " << (float)clock() / CLOCKS_PER_SEC << endl; return 0;
}

void solve() {
    int n;
    cin>>n;
    vector<long long> a(n),dp(n);
    for(int i=0;i<n;i++) {
        cin>>a[i];
    }
    long long ans = 0 , pxor = 0;
    map<long long,long long> mp;
    for(int i=0;i<n;i++) {
        pxor ^= a[i];
        if(mp.find(pxor) != mp.end()) {
            dp[i] = mp[pxor] + a[i];
        }
        else dp[i] = a[i];
        int temp = pxor ^ a[i];
        mp[temp] = dp[i];
        ans = max(ans , dp[i]);
    }
    cout<<ans<<endl;
}
