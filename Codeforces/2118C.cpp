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
    for(int i=0;i<n;i++) {
        cin>>a[i];
    }
    int req = 1;
    for(int bit = 0; bit < 61 && k >= req; bit++) {
        for(int i=0;i<n && k >= req;i++) {
            if((1 & (a[i] >> bit)) == 0) {
                // cout<<i<<" ";
                a[i] += req;
                k -= req;
                // cout<<a[i]<<endl;
                // cout<<"k: "<<k<<endl;
            }
        }
        req *= 2ll;
    }
    // for(auto it : a) {
    //     cout<<it<<" ";
    // }
    // cout<<endl;
    int cnt = 0;
    for(int i=0;i<n;i++) {
        for(int bit = 0; bit < 62; bit++) {
            if((1 & (a[i] >> bit))) {
                cnt += 1ll;
            }
        }
    }
    cout<<cnt<<endl;
}