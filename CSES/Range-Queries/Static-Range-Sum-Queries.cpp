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
    // cin>>t;
    while(t--)  solve();
    cerr << "time: " << (float)clock() / CLOCKS_PER_SEC << endl; return 0;
}

void solve() {
    int n, q;
    cin>>n>>q;
    vector<int> a(n), prefix(n+1);
    for(int i = 0; i < n; i++) {
        cin>>a[i];
        prefix[i+1] = a[i] + prefix[i];
    }
    while(q--) {
        int a, b;
        cin>>a>>b;
        a--;b--;
        cout<<prefix[b+1] - prefix[a]<<endl;
    }
}