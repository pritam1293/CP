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
    int n, q;
    cin>>n>>q;
    vector<int> a(n);
    vector<int> prefix(n+1);
    for(int i = 0; i < n; i++) {
        cin>>a[i];
        prefix[i+1] = prefix[i] ^ a[i];
    }
    while(q--) {
        int l, r;
        cin>>l>>r;
        l--;
        cout<< (prefix[r] ^ prefix[l]) <<endl;
    }
}