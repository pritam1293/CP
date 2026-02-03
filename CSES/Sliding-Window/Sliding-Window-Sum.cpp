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
    int n, k, x, a, b, c;
    cin>>n>>k>>x>>a>>b>>c;
    int ans = 0, window = 0, neg = 0, num = 0;
    for(int i = 0; i < n; i++) {
        if(i == 0) num = x;
        else num = (a*num + b) % c;
        // cout<<num<<" ";
        window += num;
        if(i >= k-1) {
            window -= neg;
            ans ^= window;
            if(i - k + 1 == 0) neg = x;
            else neg = (a*neg + b) % c;
        }
    }
    cout<<ans<<endl;
}