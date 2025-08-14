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

bool check(vector<pair<int,int>> &a, int k) {
    int left = 0, right = 0;
    for(auto& [l, r] : a) {
        left = max(left - k, l);
        right = min(right + k, r);
        if(left > right) return false;
    }
    return true;
}

void solve() {
    int n;
    cin>>n;
    vector<pair<int,int>> a(n);
    int low = 0, high = 0;
    for(int i = 0; i < n; i++) {
        cin>>a[i].first>>a[i].second;
        high = max(a[i].first, high);
        high = max(a[i].second, high);
    }
    int mid, ans = high;
    while(low <= high) {
        mid = (low + high) / 2;
        if(check(a, mid)) {
            high = mid-1;
            ans = mid;
        }
        else low = mid+1;
    }
    cout<<ans<<endl;
}