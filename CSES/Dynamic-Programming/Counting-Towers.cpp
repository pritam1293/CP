#include<bits/stdc++.h>
using namespace std;
void solve();
void countTowers();
int main() {
    countTowers();
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
//211059306
long long mod = 1e9 + 7;
vector<long long> a(1000001), b(1000001);

void countTowers() {
    int n = 1e6;
    a[1] = 1;
    b[1] = 1;
    for(int i=2;i<=n;i++) {
        a[i] = (2 * a[i-1] + b[i-1]) % mod;
        b[i] = (4 * b[i-1] + a[i-1]) % mod;
    }
}

void solve() {
    int n;
    cin>>n;
    cout<< (a[n] + b[n]) % mod <<endl;
}