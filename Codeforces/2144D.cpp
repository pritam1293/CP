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
    vector<int> a(n);
    int m = 0;
    for(int i = 0; i < n; i++) {
        cin>>a[i];
        m = max(m, a[i]);
    }
    int neg = -1e18;
    int ans = neg;
    for(int i = 2; i*i <= 2*m + 100; i++) {
        map<int, int> mp;
        for(const int& e : a) {
            mp[e]++;
        }
        vector<int> b(n);
        for(int j = 0; j < n; j++) {
            b[j] = (a[j] + i-1) / i;
        }
        int sum = 0;
        int cnt = 0;
        for(const int& e : b) {
            sum += e;
            if(mp[e] > 0) {
                mp[e]--;
            }
            else {
                cnt++;
            }
        }
        ans = max(ans, sum - cnt * k);
    }
    cout<<ans<<endl;
}