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

int gcd(int a, int b) {
    return __gcd(a, b);
}

int lcm(int a, int b) {
    return (a*b)/gcd(a, b);
}

void solve() {
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++) {
        cin>>a[i];
    }
    int g = 0, l = 1;
    reverse(a.begin(), a.end());
    for(int i = 0; i < n; i++) {
        g = gcd(g, a[i]);
        int x = a[i]/g;
        l = lcm(l, x);
    }
    cout<<l<<endl;
}