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

void solve() {
    int n, l;
    cin>>n>>l;
    vector<int> cnt(l);
    cnt[0] = 1;
    int prev = 0;
    for(int i=1;i<n;i++) {
        int d;
        cin>>d;
        prev = (prev + d) % l;
        cnt[prev]++;
    }
    if(l % 3 != 0) {
        cout<<0<<endl;
        return;
    }
    int dist = l/3;
    int ans = 0;
    for(int i=0;i<dist;i++) {
        ans += cnt[i] * cnt[i+dist] * cnt[i+dist+dist];
    }
    cout<<ans<<endl;
}