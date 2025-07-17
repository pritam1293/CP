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

bool check(int n, int k, int x) {
    int cnt = 0;
    for(int i=1;i<=n;i++) {
        cnt += (x % i == 0 ? min(x/i -1, n) : min(x/i, n));
    }
    return cnt < k;
}

void solve() {
    int n,k;
    cin>>n>>k;
    int low = 1, high = n*n;
    int ans = high;
    while(low <= high) {
        int mid = (low + high) / 2;
        if(check(n, k, mid)) {
            ans = mid;
            low = mid+1;
        }
        else {
            high = mid-1;
        }
    }
    cout<<ans<<endl;
}