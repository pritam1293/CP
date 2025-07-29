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
    int n, c;
    cin>>n>>c;
    int ans = 0;
    vector<int> a;
    for(int i = 0; i < n; i++) {
        int x;
        cin>>x;
        if(x > c) ans++;
        else a.push_back(x);
    }
    sort(a.begin(), a.end());
    while(!a.empty()) {
        while(!a.empty() && a.back() > c) {
            ans++;
            a.pop_back();
        }
        if(!a.empty()) a.pop_back();
        for(int i = 0; i < (int)a.size(); i++) {
            a[i] += a[i];
        }
    }
    cout<<ans<<endl;
}