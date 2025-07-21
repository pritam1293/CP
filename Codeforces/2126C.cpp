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
    int mx = 0;
    for(int i = 0; i < n; i++) {
        cin>>a[i];
        mx = max(mx, a[i]);
    }
    int h = a[k-1];
    if(mx == h) {
        cout<<"YES"<<endl;
        return;
    }
    sort(a.begin(), a.end());
    int p = 0;
    for(int i = 0; i < n; i++) {
        if(a[i] < h) continue;
        if(a[i] - p> h) {
            cout<<"NO"<<endl;
            return;
        }
        p = a[i];
    }
    cout<<"YES"<<endl;
}