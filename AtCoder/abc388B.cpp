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
    // cin>>t;
    while(t--)  solve();
    cerr << "time: " << (float)clock() / CLOCKS_PER_SEC << endl; return 0;
}

void solve() {
    int n,d;
    cin>>n>>d;
    vector<vector<int>> a(n,vector<int>(2));
    for(int i=0;i<n;i++) {
        cin>>a[i][0]>>a[i][1];
    }
    for(int k=1;k<=d;k++) {
        int ans = 0;
        for(int i=0;i<n;i++) {
            ans = max(ans , a[i][0] * (a[i][1] + k));
        }
        cout<<ans<<endl;
    }
}
