#include<bits/stdc++.h>
using namespace std;
#define int long long
void solve();
int32_t main() {
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

int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
}

void solve() {
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i = 0; i < n; i++) {
        cin>>a[i];
    }
    for(int i = 2; i <= 60; i++) {
        for(auto& e : a) {
            if(gcd(i, e) == 1ll) {
                cout<<i<<endl;
                return;
            }
        }
    }
    sort(a.begin(), a.end());
    for(auto& e : a) {
        if(e-1 >= 2 && gcd(e-1ll, e) == 1ll) {
            cout<<e-1<<endl;
        }
        if(gcd(e, e+1ll) == 1ll) {
            cout<<e+1<<endl;
        }
    }
}