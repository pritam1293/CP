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
    // cin>>t;
    while(t--)  solve();
    cerr << "time: " << (float)clock() / CLOCKS_PER_SEC << endl; return 0;
}

void solve() {
    double r;
    cin>>r;

    long long ans = 0;
    for(double i=0;i<r;i++) {
        double y = sqrt(r*r - (i+0.5) * (i+0.5)) - 0.5;
        ans += (long long)y;
    }
    ans *= 4;
    ans += 1ll;
    cout<<ans<<endl;
}
