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
    for(int i = 0; i < n; i++) {
        cin>>a[i];
    }
    int c1 = 0;
    int f = 1;
    for(auto& e : a) {
        if(e % 2 == f) c1++;
        f = (f+1) % 2;
    }
    int c2 = 0;
    f = 0;
    for(auto& e : a) {
        if(e % 2 == f) c2++;
        f = (f+1) % 2;
    }
    cout<<max(c1, c2)<<endl;
}