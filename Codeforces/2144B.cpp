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
    int cnt = 0;
    for(int i = 0; i < n; i++) {
        cin>>a[i];
        if(a[i] == 0) cnt++;
    }
    if(cnt > 1) {
        int left = n, right = -1;
        for(int i = 0; i < n; i++) {
            if(a[i] == 0 || a[i] != i+1) {
                left = i;
                break;
            } 
        }
        for(int i = n-1; i >= 0; i--) {
            if(a[i] == 0 || a[i] != i+1) {
                right = i;
                break;
            }
        }
        cout<<max(0ll, right - left + 1) <<endl;
    }
    else {
        int sum = 1LL * n * (n+1) / 2;
        for(auto& e : a) {
            sum -= e;
        }
        for(int i = 0; i < n; i++) {
            if(a[i] == 0) a[i] = sum;
        }
        int left = n, right = -1;
        for(int i = 0; i < n; i++) {
            if(a[i] == 0 || a[i] != i+1) {
                left = i;
                break;
            } 
        }
        for(int i = n-1; i >= 0; i--) {
            if(a[i] == 0 || a[i] != i+1) {
                right = i;
                break;
            }
        }
        cout<<max(0ll, right - left + 1) <<endl;
    }
}