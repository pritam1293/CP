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
    int n, m;
    cin>>n>>m;
    vector<string> a(n);
    vector<int> z(n);
    for(int i = 0; i < n; i++) {
        cin>>a[i];
        reverse(a[i].begin(), a[i].end());
        // cout<<a[i]<<" ";
        int j = 0, c = 0;
        while(j < (int)a[i].size() && a[i][j] == '0') c++, j++;
        z[i] = c;
    }
    int ans = 0;
    for(int i = 0; i < n; i++) {
        ans += (int)a[i].size() - z[i];
    }
    sort(z.rbegin(), z.rend());
    for(int i = 1; i < n; i += 2) {
        ans += z[i];
    }
    // cout<<ans<<endl;
    if(ans >= m+1) {
        cout<<"Sasha"<<endl;
    }
    else {
        cout<<"Anna"<<endl;
    }
}