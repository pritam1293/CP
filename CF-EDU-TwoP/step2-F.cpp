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
    int n,k;
    cin>>n>>k;
    vector<int> a(n);
    for(int i=0;i<n;i++) {
        cin>>a[i];
    }
    int l = 0;
    int ans = 0;
    deque<int> dqmin, dqmax;
    for(int r = 0; r < n; r++) {
        while(!dqmax.empty() && a[r] > dqmax.back()) dqmax.pop_back();
        while(!dqmin.empty() && a[r] < dqmin.back()) dqmin.pop_back();

        dqmax.push_back(a[r]);
        dqmin.push_back(a[r]);

        while(dqmax.front() - dqmin.front() > k) {
            if(dqmax.front() == a[l]) dqmax.pop_front();
            if(dqmin.front() == a[l]) dqmin.pop_front();
            l++;
        }
        ans += (long long)(r-l+1);
    }
    cout<<ans<<endl;
}