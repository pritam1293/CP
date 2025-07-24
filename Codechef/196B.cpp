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

void solve() {
    int n, k;
    cin>>n>>k;
    vector<int> a(n);
    int sum = 0;
    for(int i = 0; i < n; i++) {
        cin>>a[i];
        sum += a[i];
    }
    sort(a.begin(), a.end());
    bool flag = false;
    int prev = -1;
    int x = a[0], y = a[1], m;
    while(k > 0 && !flag) {
        m = (x + y + 1) / 2;
        sum += m;
        y = m;
        if(prev == m) flag = true;
        prev = m;
        k--;
    }
    m = (x + y + 1) / 2;
    sum += k * m;
    cout<<sum<<endl;
}