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
    while(t--)  solve();
    cerr << "time: " << (float)clock() / CLOCKS_PER_SEC << endl; return 0;
}

int rec(int i, vector<int> &a, vector<int> &b, int n, int h, int m) {
    if(i == a.size()) return 0;
    int ans = 0;
    if(h >= a[i] && m >= b[i]) {
        ans = max(ans, 1 + max(rec(i+1, a, b, n, h - a[i], m), rec(i+1, a, b, n, h, m - b[i])));
    }
    else if(h >= a[i]) {
        ans = max(ans, 1 + rec(i+1, a, b, n, h - a[i], m));
    }
    else if(m >= b[i]) {
        ans = max(ans, 1 + rec(i+1, a, b, n, h, m - b[i]));
    }
    return ans;
}

void solve() {
    int n, h, m;
    cin>>n>>h>>m;
    vector<int> a(n), b(n);
    for(int i=0;i<n;i++) {
        cin>>a[i]>>b[i];
    }
    cout<< rec(0, a, b, n, h, m) << endl;
}
