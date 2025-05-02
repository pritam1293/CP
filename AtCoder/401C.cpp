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
long long mod = 1e9;

void solve() {
    int n,k;
    cin>>n>>k;
    vector<long long> a(n+1);
    vector<long long> pre(n+2);

    for(int i=0;i<k && i<=n;i++) {
        a[i] = 1;
        pre[i+1] = pre[i] + a[i];
    }
    for(int i=k;i<=n;i++) {
        a[i] = (pre[i] - pre[i-k] + mod) % mod;
        pre[i+1] = (pre[i] + a[i]) % mod;
    }
    cout<< a[n] % mod <<endl;
}