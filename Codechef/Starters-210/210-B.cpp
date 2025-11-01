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
    for(int i = 0; i < n; i++) {
        cin>>a[i];
    }
    vector<int> c = a;
    sort(a.begin(), a.end());
    map<int, int> mp;
    mp[a[0]] = -1;
    mp[a[n-1]] = -1;
    for(int i = 1; i < n-1; i++) {
        int left = a[i] - a[i-1] - 1;
        left /= 2;
        int right = a[i+1] - a[i];
        right /= 2;
        mp[a[i]] = left + right + 1;
    }
    for(auto& e : c) {
        cout<<mp[e]<<" ";
    }
    cout<<endl;
}