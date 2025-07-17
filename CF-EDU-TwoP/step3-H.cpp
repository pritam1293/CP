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
    while(t--)  solve();
    cerr << "time: " << (float)clock() / CLOCKS_PER_SEC << endl; return 0;
}

void solve() {
    int n, m, s, wa, wb;
    cin>>n>>m>>s>>wa>>wb;
    vector<int> a(n), b(m);
    for(int i=0;i<n;i++) {
        cin>>a[i];
    }
    for(int i=0;i<m;i++) {
        cin>>b[i];
    }
    sort(a.rbegin(), a.rend());
    sort(b.rbegin(), b.rend());

    int r = min(n, s/wa) - 1;
    int sum = (r+1) * wa;
    int cost = 0;
    for(int i=0;i<=r;i++) cost += a[i];
    int curr = cost;
    m = min(m, s/wb);
    for(int i=0;i<m;i++) {
        curr += b[i];
        sum += wb;
        while(sum > s) {
            sum -= wa;
            curr -= a[r];
            r--;
        }
        cost = max(cost, curr);
    }
    cout<<cost<<endl;
}