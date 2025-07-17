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
    int n, q;
    cin>>n>>q;
    vector<int> a(n);
    for(int i=0;i<n;i++) {
        cin>>a[i];
    }
    vector<int> pos(n+1);
    for(int i=0;i<q;i++) {
        int l, r;
        cin>>l>>r;
        l--;r--;
        pos[l]++;
        pos[r+1]--;
    }
    // cout<<pos[0]<<" ";
    for(int i=1;i<n;i++) {
        pos[i] += pos[i-1];
        // cout<<pos[i]<<" ";
    }
    pos.pop_back();
    sort(pos.begin(), pos.end());
    sort(a.begin(), a.end());
    int sum = 0;
    for(int i=0;i<n;i++) {
        sum += pos[i]*a[i];
    }
    cout<<sum<<endl;
}