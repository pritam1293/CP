#include<bits/stdc++.h>
using namespace std;
void solve();
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int t=1;
    while(t--)  solve();
    cerr << "time: " << (float)clock() / CLOCKS_PER_SEC << endl; return 0;
}

void solve() {
    vector<int> a= {3,3,4};
    int k = 0;
    long long mod = 1e9 + 7;
    int n = a.size();
    vector<int> pre(n+1);
    pre[0] = 1;
    int l = 0;
    int ans = 0;
    deque<int> dqmin, dqmax;
    for(int r = 0; r < n; r++) {
        while(!dqmax.empty() && a[r] > dqmax.back()) dqmax.pop_back();
        while(!dqmin.empty() && a[r] < dqmin.back()) dqmin.pop_back();
 
        dqmax.push_back(a[r]);
        dqmin.push_back(a[r]);
 
        while(!dqmax.empty() && !dqmin.empty() && dqmax.front() - dqmin.front() > k) {
            if(dqmax.front() == a[l]) dqmax.pop_front();
            if(dqmin.front() == a[l]) dqmin.pop_front();
            l++;
        }

        long long val = pre[r];
        if(l > 0) val = (val - pre[l-1] + mod) % mod;
        pre[r+1] = (pre[r] + val) % mod;
    }
    cout<<(pre[n]-pre[n-1] + mod) % mod<<endl;
    cout<<ans<<endl;
}
