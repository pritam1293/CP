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

void solve() {
    int n;
    cin>>n;
    vector<int> a(n);
    bool odd = false, even = false;
    for(int i = 0; i < n; i++) {
        cin>>a[i];
        if(a[i] % 2) odd = true;
        else even = true;
    }
    if(odd && even) {
        sort(a.begin(), a.end());
    }
    for(auto& e : a) {
        cout<<e<<" ";
    }
    cout<<endl;
}