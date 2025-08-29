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
    // cin>>t;
    while(t--)  solve();
    cerr << "time: " << (float)clock() / CLOCKS_PER_SEC << endl; return 0;
}

void solve() {
    int n, m;
    cin>>n>>m;
    string s, t;
    cin>>s>>t;
    vector<int> segment(n+1);
    for(int i = 0; i < m; i++) {
        int l, r;
        cin>>l>>r;
        l--;r--;
        segment[l]++;
        segment[r+1]--;
    }
    int sum = 0;
    for(int i = 0; i < n; i++) {
        sum += segment[i];
        if(sum % 2 == 0) continue;
        swap(s[i], t[i]);
    }
    cout<<s<<endl;
}