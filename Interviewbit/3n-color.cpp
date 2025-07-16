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
    while(t--)  solve();
    cerr << "time: " << (float)clock() / CLOCKS_PER_SEC << endl; return 0;
}

long long mod = 1e9 + 7;

int color(int n) {
    long long color3 = 24;
    long long color2 = 12;
    long long temp;
    for(int i=2;i<=n;i++) {
        temp = (11 * color3 + 10 * color2) % mod;
        color2 = (5 * color3 + 7 * color2) % mod;
        color3 = temp;
    }
    long long ans = (color2 + color3) % mod;
    return (int)ans;
}

void solve() {
    int n = 2;
    cout<<color(n)<<endl;
}
