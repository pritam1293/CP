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

bool check(vector<int> &a, vector<int> &b, int n, int k, int x) {
    int cnt = 0;
    int j = n-1;
    for(int i=0;i<n && j >= 0;i++) {
        while(a[i] + b[j] >= x && j >= 0) {
            j--;
        }
        if(a[i] + b[j] < x) {
            cnt += j+1;
        }
    }
    return cnt < k;
}

void solve() {
    int n,k;
    cin>>n>>k;
    vector<int> a(n), b(n);
    for(int i=0;i<n;i++) {
        cin>>a[i];
    }
    for(int i=0;i<n;i++) {
        cin>>b[i];
    }
    sort(a.begin(),a.end());
    sort(b.begin(),b.end());

    int low = 1, high = 2e9;
    int ans = high;
    while(low <= high) {
        int mid  = (low + high) / 2;
        if(check(a, b, n, k, mid)) {
            ans = mid;
            low = mid+1;
        }
        else {
            high = mid-1;
        }
    }
    cout<<ans<<endl;
}