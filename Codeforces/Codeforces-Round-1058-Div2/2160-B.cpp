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
    cout<<n<<endl;
    vector<int> a(n);
    for(int i = 0; i < n; i++) {
        cin>>a[i];
    }  
    vector<int> ans(n);
    for(int i = 0; i < n; i++) {
        ans[i] = i+1;
    }
    for(int i = 1; i < n; i++) {
        int extra = a[i] - ans[i-1];
        // cout<<extra<<" ";
        ans[i] = ans[i-1] + i-extra+1;
    }
    for(auto& e : ans) {
        cout<<e<<" ";
    }
    cout<<endl;
}