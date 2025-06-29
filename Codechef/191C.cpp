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

bool check(vector<int> &a, vector<int> &b, int mid, int n) {
    int need = 0, have = 0;
    for(int i = 0; i < n; i++) {
        int sum = a[i] + b[i];
        if(sum <= mid) {
            have += (mid - sum) / 2;
        } else {
            need += sum - mid;
        }
    }
    return have >= need;
}

void solve() {
    int n;
    cin>>n;
    vector<int> a(n), b(n);
    int mx = 0;
    for(int i=0;i<n;i++) {
        cin>>a[i];
        mx = max(mx, a[i]);
    }
    int sum = 0;
    for(int i=0;i<n;i++) {
        cin>>b[i];
        sum += b[i];
    }    
    int low = mx;
    int high = 2e9;
    int ans = high;
    while(low <= high) {
        int mid = (low + high) / 2;
        if(check(a, b, mid, n)) {
            high = mid-1;
            ans = mid;
        }
        else low = mid+1;
    }
    cout<<ans<<endl;
}