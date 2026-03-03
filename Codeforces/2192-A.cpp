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
    string s;
    cin>>s;
    int cnt = 1;
    for(int i = 1; i < n; i++) {
        if(s[i] != s[i-1]) cnt++;
    }
    if(s[0] != s[n-1]) {
        cout<<min(n, cnt+1)<<endl;
    }
    else {
        cout<<cnt<<endl;
    }
}