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

bool half(int a, int b) {
    return max(a, b) <= 2 * min(a, b) + 2;
}

void solve() {
    int a, b, c, d;
    cin>>a>>b>>c>>d;
    c -= a;
    d -= b;
    if(half(a, b) && half(c, d)) {
        cout<<"YES"<<endl;
    }
    else {
        cout<<"NO"<<endl;
    }
}