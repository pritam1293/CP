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
    map<int,int> mp;
    for(int i= 0; i < n; i++) {
        cin>>a[i];
        if(a[i] != 1) cnt++;
        mp[a[i]]++;
    }
    int val = -1, fr = 0;
    for(auto& [f, s] : mp) {
        if(s > fr) {
            fr = s;
            val = f;
        }
    }
    if(val == 1) {
        cout<<cnt<<endl;
        return;
    }
    cout<<min(cnt, n-fr+1)<<endl;
}