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
    for(int i = 0; i < n; i++) {
        cin>>a[i];
    }
    int c = 0, ans = 0;
    bool flag = false;
    for(int i = 0; i < n; i++) {
        if(flag) {
            flag = false;
            continue;
        }
        if(a[i] == 0) c++;
        else c = 0;
        if(c == k) {
            flag = true;
            ans++;
            c = 0;
        }
    }
    cout<<ans<<endl;
}