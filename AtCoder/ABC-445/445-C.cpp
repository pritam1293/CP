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
    while(t--)  solve();
    cerr << "time: " << (float)clock() / CLOCKS_PER_SEC << endl; return 0;
}

void solve() {
    int n;
    cin>>n;
    vector<int> a(n+1);
    for(int i = 1; i <= n; i++) {
        cin>>a[i];
    }
    vector<int> ans(n+1);
    for(int i = n; i > 0; i--) {
        if(a[i] == i) ans[i] = i;
        else ans[i] = ans[a[i]];
    }
    for(int i = 1; i <= n; i++) {
        cout<<ans[i]<<" ";
    }
    cout<<endl;
}