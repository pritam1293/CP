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
    int n, m, h;
    cin>>n>>m>>h;
    vector<int> a(n), b(m), c(m);
    for(int i = 0; i < n; i++) {
        cin>>a[i];
    }
    vector<int> cnt(n);
    vector<int> update(n);
    int last = 0;
    for(int i = 0; i < m; i++) {
        int b, c;
        cin>>b>>c;
        b--;
        if(last > update[b]) {
            cnt[b] = c;
        }
        else {
            cnt[b] += c;
        }
        if(cnt[b] + a[b] > h) {
            cnt[b] = 0;
            last = i;
        }
        update[b] = i;
    }
    for(int i = 0; i < n; i++) {
        if(last > update[i]) cnt[i] = 0;
        cout<<a[i] + cnt[i]<<" ";
    }
    cout<<endl;
}