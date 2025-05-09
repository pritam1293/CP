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
    while(t--)  solve();
    cerr << "time: " << (float)clock() / CLOCKS_PER_SEC << endl; return 0;
}

bool check(vector<pair<int, int>> &a, int n, int k, int x) {
    int cnt = 0;
    for(int i=0;i<n;i++) {
        if(a[i].first > x) continue;
        else if(a[i].second < x) cnt += a[i].second - a[i].first + 1;
        else cnt += x - a[i].first;
    }
    return cnt <= k;
}

void solve() {
    int n, k;
    cin>>n>>k;
    vector<pair<int, int>> a(n);
    for(int i=0;i<n;i++) {
        cin>>a[i].first>>a[i].second;
    }
    int low = -2e9, high = 2e9;
    int ans = 2e9;
    while(low <= high) {
        int mid = (low + high) / 2;
        if(check(a, n, k, mid)) {
            low = mid+1;
            ans = mid;
        }
        else {
            high = mid-1;
        }
    }
    cout<<high<<endl;
}