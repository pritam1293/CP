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
    int neg = 0, z = 0;
    for(int i = 0; i < n; i++) {
        int x;
        cin>>x;
        if(x == 0) z++;
        else if(x == -1) neg++;
    }
    neg %= 2;
    cout<< neg * 2 + z <<endl;
}