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
    int a, b;
    cin>>a>>b;
    // cout<<log2(1e18)<<endl;
    if(a == b) {
        cout<<"-1"<<endl;
    }
    else {
        cout<< (int)(pow(2, 36) - max(a, b)) <<endl;
    }
}