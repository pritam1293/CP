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
    cin>>t;
    while(t--)  solve();
    cerr << "time: " << (float)clock() / CLOCKS_PER_SEC << endl; return 0;
}

void solve() {
    int s, k, m;
    cin>>s>>k>>m;
    int n = m / k;
    int rem = m % k;
    int curr = s;
    if (k < s && n % 2 != 0) {
        curr = k;
    }
    cout<<max(0LL, curr - rem)<<endl;
}