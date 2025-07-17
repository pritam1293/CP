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
    set<pair<int,int>> st;
    for(int i=0;i<n;i++) {
        int x, y;
        cin>>x>>y;
        st.insert({x, y});
    }
    int cnt = 0;
    for(auto& [x, y] : st) {
        if(st.count({x+2, y}) && st.count({x+1, (y^1)})) cnt++;
        if(y == 0 && st.count({x, 1})) cnt += n-2;
    }
    cout<<cnt<<endl;
}