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
    while(t--)  solve();
    cerr << "time: " << (float)clock() / CLOCKS_PER_SEC << endl; return 0;
}

void solve() {
    int n;
    cin>>n;
    vector<string> a(n);
    int m = 0;
    for(auto& s : a) {
        cin>>s;
        m = max(m, (int)s.size());
    }
    for(auto& s : a) {
        int k = (m - (int)s.size()) / 2;
        for(int i = 0; i < k; i++) {
            cout<<".";
        }
        cout<<s;
        for(int i = 0; i < k; i++) {
            cout<<".";
        }
        cout<<endl;
    }
}