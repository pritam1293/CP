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
    int n, h, k;
    cin>>n>>h>>k;
    vector<int> a(n);
    int sum = 0;
    for(auto& e : a) {
        cin>>e;
        sum += e;
    }
    int reload = h / sum;
    h %= sum;
    int ans = reload * (k + n);
    if(h == 0) {
        cout<<ans - k<<endl;
        return;
    } 
    vector<int> suffix(n, a[n-1]);
    for(int i = n-2; i >= 0; i--) {
        suffix[i] = max(suffix[i+1], a[i]);
    }
    sum = 0;
    int minm = a[0], uses = n;
    for(int i = 0; i < n-1; i++) {
        sum += a[i];
        minm = min(minm, a[i]);
        int s = max(sum, sum - minm + suffix[i+1]);
        if(s >= h) {
            uses = i+1;
            break;
        }
    }
    cout<<ans + uses<<endl;
}