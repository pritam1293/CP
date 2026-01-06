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
    // cin>>t;
    while(t--)  solve();
    cerr << "time: " << (float)clock() / CLOCKS_PER_SEC << endl; return 0;
}

void solve() {
    int n;
    cin>>n;
    vector<int> cnt(n+1);
    for(int i = 1; i*i < n; i++) {
        for(int j = i+1; j*j < n; j++) {
            int num = i*i + j*j;
            if(num > n) break;
            cnt[num]++;
        }
    }
    vector<int> ans;
    for(int i = 1; i <= n; i++) {
        if(cnt[i] == 1) ans.push_back(i);
    }
    // cout<<mp.size()<<endl;
    cout<<(int)ans.size()<<endl;
    for(auto& e : ans) {
        cout<<e<<" ";
    }
}