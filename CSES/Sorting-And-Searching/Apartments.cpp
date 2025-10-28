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
    while(t--)  solve();
    cerr << "time: " << (float)clock() / CLOCKS_PER_SEC << endl; return 0;
}

bool check(vector<int> &a, vector<bool> &vis, int low, int high, int minm, int maxm) {
    int mid, idx = -1;
    while(low <= high) {
        mid = (low + high) / 2;
        if(a[mid] >= minm && a[mid] <= maxm) {
            if(vis[mid]) {
                high = mid-1;
            }
            else {
                idx = mid;
                low = mid+1;
            }
        }
        else if(a[mid] < minm) {
            low = mid+1;
        }
        else {
            high = mid-1;
        }
    }
    if(idx == -1) return false;
    vis[idx] = true;
    return true;
}

void solve() {
    int n, m, k;
    cin>>n>>m>>k;
    vector<int> a(n), b(m);
    for(int i = 0; i < n; i++) cin>>a[i];
    for(int i = 0; i < m; i++) cin>>b[i];
    sort(b.begin(), b.end());
    sort(a.rbegin(), a.rend());
    int cnt = 0;
    vector<bool> vis(m, false);
    for(auto& e : a) {
        if(check(b, vis, 0, m-1, e-k, e+k)) cnt++;
    }
    cout<<cnt<<endl;
}