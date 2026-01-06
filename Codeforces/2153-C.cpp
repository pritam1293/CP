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
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i = 0; i < n; i++) {
        cin>>a[i];
    }
    map<int, int> mp;
    for(auto& e : a) {
        mp[e]++;
    }
    int sum = 0;
    vector<int> odd, even;
    for(auto& [key, val] : mp) {
        sum += key * (val - val % 2);
        if(val % 2) odd.push_back(key);
        else even.push_back(key);
    }
    if(sum == 0) {
        cout<<0<<endl;
        return;
    }
    int ans = 0;
    for(auto& e : odd) {
        if(sum > e) ans = max(ans, sum + e);
    }
    for(int i = 1; i <(int)odd.size(); i++) {
        if(sum > abs(odd[i] - odd[i-1])) {
            ans = max(ans, odd[i] + odd[i-1] + sum);
        }
    }
    for(auto& e : even) {
        if(sum/2 - e > 0) ans = max(ans, sum);
    }
    cout<<ans<<endl;
}