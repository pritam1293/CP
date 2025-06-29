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
    int low = 1, high = n;
    int ans = 0;
    int i = 0;
    while(low <= high) {
        int mid = (low + high) / 2;
        // cout<<mid<<endl;
        int pre = (k + mid - 1 + k) * mid/2ll;
        int post = (k+mid + k + n-1) * (n-mid)/2ll;
        if(pre <= post) {
            ans = post-pre;
            i = mid;
            low = mid+1;
        }
        else {
            high = mid-1;
        }
    }
    i++;
    int pre = (k + i - 1 + k) * i/2ll;
    int post = (k+i + k + n-1) * (n-i)/2ll;
    ans = min(ans, abs(pre-post));
    cout<<ans<<endl;
}