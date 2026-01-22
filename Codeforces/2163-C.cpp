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

vector<vector<int>> prefix, suffix;

bool check(int l, int r, int n) {
    int left = -1, right = n+1;
    int low = 0, high = n-1, mid;
    while(low <= high) {
        mid = (low + high) / 2;
        if(prefix[mid][0] >= l && prefix[mid][1] <= r) {
            left = mid;
            low = mid+1;
        }
        else high = mid-1;
    }
    low = 0; high = n-1;
    while(low <= high) {
        mid = (low + high) / 2;
        if(suffix[mid][0] >= l && suffix[mid][1] <= r) {
            right = mid;
            high = mid-1;
        }
        else low = mid+1;
    }
    return left >= right;
}

void solve() {
    int n;
    cin>>n;
    vector<vector<int>> a(2, vector<int>(n));
    for(auto& it : a) {
        for(auto& e : it) {
            cin>>e;
        }
    }
    prefix = vector<vector<int>>(n, vector<int>(2));
    prefix[0][0] = a[0][0];
    prefix[0][1] = a[0][0];
    for(int i = 1; i < n; i++) {
        prefix[i][0] = min(prefix[i-1][0], a[0][i]);
        prefix[i][1] = max(prefix[i-1][1], a[0][i]);
    }
    suffix = vector<vector<int>>(n, vector<int>(2));
    suffix[n-1][0] = a[1][n-1];
    suffix[n-1][1] = a[1][n-1];
    for(int i = n-2; i >= 0; i--) {
        suffix[i][0] = min(suffix[i+1][0], a[1][i]);
        suffix[i][1] = max(suffix[i+1][1], a[1][i]);
    }
    int ans = 0;
    for(int l = 1; l <= 2*n; l++) {
        int low = l, high = 2*n, r = 2*n + 1, mid;
        while(low <= high) {
            mid = (low + high) / 2;
            if(check(l, mid, n)) {
                r = mid;
                high = mid-1;
            }
            else low = mid+1;
        }
        ans += 2*n - r + 1;
    }
    cout<<ans<<endl;
}