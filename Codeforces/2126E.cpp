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

void solve() {
    int n;
    cin>>n;
    vector<int> p(n), s(n);
    for(int i = 0; i < n; i++) cin>>p[i];
    for(int i = 0; i < n; i++) cin>>s[i];
    if(s[0] != p[n-1]) {
        cout<<"NO"<<endl;
        return;
    }
    int g = p[n-1];
    for(int i = 1; i < n; i++) {
        if(p[i-1] % p[i] != 0) {
            cout<<"NO"<<endl;
            return;
        }
    }
    for(int i = 1; i < n; i++) {
        if(s[i] % s[i-1] != 0) {
            cout<<"NO"<<endl;
            return;
        }
    }
    for(int i = 0; i < n; i++) {
        if(gcd(p[i], s[i]) != g) {
            cout<<"NO"<<endl;
            return;
        }
    }
    for(int i = 1; i < n; i++) {
        if(gcd(p[i-1], s[i]) != g) {
            cout<<"NO"<<endl;
            return;
        }
    }
    cout<<"YES"<<endl;
}