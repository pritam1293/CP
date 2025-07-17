#include<bits/stdc++.h>
using namespace std;
void solve();
int main() {
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
vector<int> v;

bool check(vector<int> &a, int n, int mid, int k) {
    int cnt = 0;
    int mex = 0;
    for(int i = 0; i < n; i++) {
        if(a[i] <= n+1) v[a[i]] = 1;
        while(v[mex]) mex++;
        if(mex >= mid) {
            cnt++;
            for(int j = 0; j < min(mid+1, n+2); j++) {
                v[j] = 0;
            }
            mex = 0;
        }
    }
    for(int i = 0; i < n+2; i++) v[i] = 0;
    return cnt >= k;
}

void solve() {
    int n, k;
    cin>>n>>k;
    vector<int> a(n);
    for(int i=0;i<n;i++) {
        cin>>a[i];
    }
    v = vector<int>(n+5);
    int low = 0, high = n+1;
    int ans = high;
    while(low + 1 < high) {
        int mid = low + (high - low) / 2;
        if(check(a, n, mid, k)) {
            ans = mid;
            low = mid;
        }
        else {
            high = mid;
        }
    }
    cout<<low<<endl;
}