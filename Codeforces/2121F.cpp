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
    int n, s, x;
    cin>>n>>s>>x;
    vector<int> a(n+1),  prefix(n+1);
    for(int i=1;i<=n;i++) {
        cin>>a[i];
        prefix[i] = prefix[i-1] + a[i];
    }
    map<int,int> cnt;
    int l = 1, ans = 0;
    for(int r = 1; r <= n; r++) {
        if(a[r] > x) {
            cnt.clear();
            l = r+1;
        }
        else if(a[r] == x) {
            while(l <= r) {
                cnt[prefix[l-1]]++;
                l++;
            }
        }
        ans += cnt[prefix[r]-s];
    }
    cout<<ans<<endl;
}