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
    int n,k;
    cin>>n>>k;
    vector<long long> a(n);
    for(int i=0;i<n;i++) {
        cin>>a[i];
    }

    if(k == 1) {
        long long mx = 0;
        for(int i=1;i<n;i++) {
            mx = max(a[i], mx);
        }

        long long ans = a[0] + mx;
        mx = 0;

        for(int i=1;i<n;i++) {
            mx = max(a[i-1], mx);
        }
        ans = max(ans , mx + a[n-1]);

        cout<<ans<<endl;
        return;
    }

    sort(a.rbegin(),a.rend());
    long long ans = 0;
    for(int i=0;i<=k;i++) {
        ans += a[i];
    }
    cout<<ans<<endl;
}