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

int sum(int l, int r, int n) {
    return (l+r) * n / 2ll;
}

int lcm(int a, int b) {
    return (a*b)/__gcd(a, b);
}

void solve() {
    int n, x, y;
    cin>>n>>x>>y;
    int ans = 0;
    // if(x % y == 0) {
    //     int cnt = (n / y - n / (x*y)) - (n / x - n / (x*y));
    //     ans -= sum(1, cnt, cnt);
    // } 
    // else {
    //     int cnt = n/x - n/(lcm(x, y));
    //     ans += sum(n, n-cnt+1, cnt);
    //     cout<<cnt<<endl;
    //     cnt = n/y - n/(lcm(x, y));
    //     ans -= sum(1, cnt, cnt);
    // }
    int cnt = n/x - n/(lcm(x, y));
    ans += sum(n, n-cnt+1, cnt);
    // cout<<cnt<<endl;
    cnt = n/y - n/(lcm(x, y));
    ans -= sum(1, cnt, cnt);
    cout<<ans<<endl;
}